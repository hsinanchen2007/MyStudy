### 解题思路
做了一下午，自己找到了这道题的规律，本质上就是一个插入排序，只不过排序的规则略有不同。方法确实不好，速度太慢了，不过可以解出来。感兴趣的可以看一看。
![image.png](https://pic.leetcode-cn.com/deea53f82e07f5f2cc336e1290eaa16b38c984c4bc7fdd226f281073cb6b7bc6-image.png)
简单说一下我的方法：
1.使用list存新的排序系列，因为需要经常的插入操作且不用随机访问，所以我选了list。
2.对nums中的每一个数进行遍历，并把他们转化为string。
3.用nums中的每一个元素和list中的元素比较，找到插入点。（list中的顺序就是结果的顺序）
4.因为上面两个string组合的不好找规律，我就把两个string分别加到一起。（num+tmp和tmp+num）这样就可以方便判断大小，从而找到插入位置。
5.遍历结束，把list中的元素加到一起，就是最后的值。要注意把该字符串开头的0去掉。


### 代码

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int len=nums.size();
        if(len==0) return "";

        list<string> res;
        res.insert(res.begin(),to_string(nums[0]));//注意：list的迭代器方法是begin(res)和end(res),我懒得改了，不过也可以编译
        for(int i=1; i<len; ++i){
            string num=to_string(nums[i]);
            auto it=res.begin();
            while(it!=res.end())
            {
                string tmp=*it;
                string s1=tmp+num;
                string s2=num+tmp;
                int flag=0;//s1大返回0，s2大返回1，相等返回1
                int i_s1=0,i_s2=0;
                while(i_s1<s1.size()&&i_s2<s2.size())
                {
                    if(s1[i_s1]>s2[i_s2])
                        break;
                    else if(s1[i_s1]<s2[i_s2])
                    {
                        flag=1;
                        break;
                    }
                    else
                    {
                        ++i_s1;
                        ++i_s2;
                    }
                }
                if(i_s1==s1.size()&&i_s2==s2.size())
                    flag=1;
                if(flag==1)
                    break;
                ++it;
            }
            res.insert(it,num);
        }
        string output;
        for(auto it=res.begin(); it!=res.end(); ++it)
            output+=*it;
        int i=0;
        while(output[i]=='0'&&i<output.size()-1)
            ++i;
        output.erase(0,i-0);
        return output;
    }
};
```