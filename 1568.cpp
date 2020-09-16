class Solution
{
public:
    int n,m;    //数组的长宽
    vector<vector<bool>> st;    //状态数组
    vector<vector<int>> g;
    int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
    
    void dfs(int x, int y)  //2.遍历
    {
        st[x][y]=true;
        for(int i=0;i<4;i++)
        {
            int a=x+dx[i], b=y+dy[i];     //遍历四个方向的点，使用偏移量dx，dy
            if(a>=0 && a<n && b>=0 && b<m && !st[a][b] && g[a][b]==1)   //未越界 且 未遍历 且 为1
                dfs(a,b);
        }
    }
    
    bool check()    //1.判断连通块数量是否大于1/等于0
    {
        int cnt=0;  //连通块的数量
        st = vector<vector<bool>>(n,vector<bool>(m));//将状态数组清空
        for(int i=0;i<n;i++)//枚举所有是1的点
            for(int j=0;j<m;j++)
                if(!st[i][j] && g[i][j]==1)
                {
                    cnt++;
                    dfs(i,j);
                }
        
        return (cnt>1 || cnt==0);
    }
    
    int minDays(vector<vector<int>>& grid)
    {
        n=grid.size(), m=grid[0].size();
        g=grid;
        
        if(check()) return 0;   //有大于1个的连通块 不用操作 输出0
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j])
                {
                    g[i][j]=0;
                    if(check()) return 1;   //删除一个陆地后进行判断 如果cnt>1 执行一步；否则恢复现场
                    g[i][j]=1;
                }
        
        return 2;   //默认一定有解 最多2步
    }
};
