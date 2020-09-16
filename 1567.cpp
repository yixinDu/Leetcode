class Solution
{
public:
    int getMaxLen(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> f(n),g(n);  //声明vector数组
        if(nums[0]>0) f[0]=1;   //1表示长度
        if(nums[0]<0) g[0]=1;
        
        int res=f[0];
        for(int i=1;i<n;i++)    //因为上面已经判断过第0个元素的正负了
        {
            if(nums[i]>0)
            {
                f[i]=f[i-1]+1;
                if(g[i-1]>0) g[i]=g[i-1]+1;
            }
            if(nums[i]<0)
            {
                if(g[i-1]>0) f[i]=g[i-1]+1;
                g[i]=f[i-1]+1;
            }
            res=max(res,f[i]);
        }
        return res;
    }
};
