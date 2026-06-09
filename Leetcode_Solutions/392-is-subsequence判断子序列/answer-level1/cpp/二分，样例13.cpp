右边界是0时候的处理

1.处理单字母时eg： a，二分返回left=0，因为tag=-1，所以不能以vt[now][left]!=tag来判定，这样返回的是false

2.因为tag是变动的，假设第一次返回是记录首字母的位置tag=0，right=-1的时候，返回还是left=0，tag=0,就会出现死循环

//个人觉得这题大于等于或大于都可以，因为是个严格单调递增的字符串，那么保证位置只会出现一次
至于测试样例13很奇怪，删光了y的确不匹配，提交正确率降低了不少，可能是我太菜了

![](https://pic.leetcode-cn.com/b1d065b2ab7b7f728f030670b642c03677cce682c4ce5a5e3abe7f6439f154ea-file_1583648481280)

![我把你的y都删了，请问为啥两个字符串可以匹配成功呢~](https://pic.leetcode-cn.com/46af64bd681ee5de270c38352809537f169be2c0aaa4a4ce24ca33fb00158d69-file_1583648481283)


```
bool isSubsequence(string s, string t) {
        vector<vector<int> >vt(26);
        for(int i=0;i<t.size();i++)
            vt[t[i]-'a'].push_back(i);
        int tag=-1;
        for(int i=0;i<s.size();i++)
        {
            int now=s[i]-'a';
            int mid,left=0,right=vt[now].size()-1;
            if(right==-1)return false;
            //在原序列中查找第一个字母对应下标大于tag的位置是否存在
            while(left<right)
            {
                mid=(left+right)/2;
                if(vt[now][mid]>tag)
                    right=mid;
                else
                    left=mid+1;
            }
            if(vt[now][left]<tag)
                return false;
            tag=vt[now][left];
        }
        return true;
    }
```