### 解题思路
根据双指针思路进行，注意一些临界条件。

### 代码

```csharp
public class Solution {
    public int LengthOfLongestSubstring(string s) {
         if(s.Length==0)return 0;
     Hashtable hash=new Hashtable(s.Length);
            int maxLen=1;
            int len=1;
            int tail=1;
             hash.Add(s[0],0);
//重复字符往后走
      for(int i=0;i<s.Length-1;i++){
       //不重复 指针往后挪，并判断是否是出现过的字符
       for(int j=tail;(j<s.Length)&&(!hash.ContainsKey(s[j]));j++){
        hash.Add(s[j],j); 
         len++;
                    tail=j+1;//保存尾部指针
        }
        hash.Remove(s[i]);//将头元素从哈希表删去   
         
                if(len>maxLen) maxLen=len;//更新最大值
        
        len--;//更新最大值之后 由于哈希表中移除首结点 哈希表长度减一
         
            if(len==0){tail=(i+1);}//"aab"字符串 特殊情况 手动改值 
        
      }

        return maxLen;
    }
}
```