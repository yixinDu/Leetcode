class Solution
{
public:
    bool containsPattern(vector<int>& arr, int m, int k)
    {
        int n=arr.size();
        for(int i=0;i+k*m<=n;i++)    //遍历i后的k*m段（长度不能超过n）
        {
            bool flag=true;
            for(int j=i;j<i+k*m;j++)   //遍历k*m段是否有k个m
                if(arr[j]!=arr[i + (j-i)%m])   //(j-i)%m在一段内的相对位置 + i偏移量
                {
                    flag=false;
                    break;
                }
            if(flag) return true;
        }
        return false;
    }
};
