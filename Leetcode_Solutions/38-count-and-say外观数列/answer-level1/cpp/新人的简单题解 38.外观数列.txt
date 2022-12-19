### 解题思路
PAT乙级也有这个题，以前没做出来，现在想了想忽然明白了，还是依靠双指针，一个指针指向每段的首个元素，j负责向后数重复个数，直到遇到不同元素为止，然后更新i的位置，空间上利用temp和s两个字符串不断做更新即可。

由于主要是对每段的所有字符与每段起始字符做比较（严格来说，每段结束字符的下一个字符也要被比较一次），几乎没有重复遍历；对i,j移动和赋值若干次和对字符串每段做两次push_back操作（这些都只与段数有关），因此其时间复杂度主要和字符串长度有关，几乎是O(n),效率还是不错的

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n)
    {
        
        string s="";
        string temp="1";
        if(n==1) return "1";
        int i,j;
        for(int k=0;k<n-1;k++)
        {   
            
            for(int i=0;i<temp.length();i++)
            {
                
                for(j=i;temp[j]==temp[i];j++);
                s.push_back('0'+j-i);
                s.push_back(temp[i]);
                i=j-1;
            }
            temp=s;
            s="";
        }
        return temp;
    }
};
```