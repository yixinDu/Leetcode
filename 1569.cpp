typedef long long LL;//乘法 防止溢出，爆int

class Solution
{
public:
    vector<vector<int>> C;  //定义组合数的数组
    const int MOD = 1e9+7;  //自己定义
    
    int numOfWays(vector<int>& nums)
    {
        int n=nums.size();
        C=vector<vector<int>>(n+1,vector<int>(n+1));    //C的大小重新初始化
        for(int i=0;i<=n;i++)   //递推每个C的值
            for(int j=0;j<=i;j++)
                if(!j) C[i][j]=1;
                else C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        
        return (f(nums) + MOD - 1) % MOD; //除去已经有的方案
    }
    
    int f(vector<int> nums)
    {
        if(nums.empty()) return 1;  //nums为空
        int n=nums.size();
        int k=nums[0];  //数组的第一个元素 根结点不变
        vector<int> left,right; //以根结点为界将数字分为两类，比k小的和比k大的
        for(auto x: nums)
        {
            if(x<k) left.push_back(x);
            if(x>k) right.push_back(x-k);
        }
        return (LL)C[n-1][k-1] * f(left) % MOD * f(right) % MOD;
    }
};
