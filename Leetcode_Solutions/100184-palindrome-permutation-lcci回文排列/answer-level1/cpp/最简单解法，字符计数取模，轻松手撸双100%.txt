class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> arr(256,0);
        //把所有ASCII字符囊括进来
        for(int i=0;i<s.length();i++)
            arr[s[i]]=(arr[s[i]]+1)%2;  //取模2，只要两两相同，就去消掉
        //一开始只搞了个s[i]-'a'，后来发现例子里面还有字母外的其他字符
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
        }
        if(sum==1||sum==0)
        //最后剩一个或者全为0的时候，对应奇数偶数两种状态
            return true;
        else
            return false;
    }
};