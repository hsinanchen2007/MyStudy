**题解**：滑动窗口

**窗口**：t和s的相对应的子字符串做差值之后的cost。若窗口内的cost小于等于maxCost时，我们需要记录最长的子字符串；若cost大于maxCost的话，表示窗口溢出，我们需要缩小窗口了。

**相似题目**：[424.替换后的最长重复字符](https://blog.csdn.net/qq_43152052/article/details/102578696)

**代码如下**：
```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left=0,right=0,result=0,cost=0,n=s.size();
        
        while(right<n){//固定窗口的边界
            cost+=abs(s[right]-t[right]);
            
            while(cost>maxCost){//窗口溢出，需要缩小窗口
                cost-=abs(s[left]-t[left]);
                left++;
            }
            //窗内中cost小于等于maxCost时，我们需要记录最长的子字符串
            result=max(result,right-left+1);
            right++;
        }
        return result;
    }
};
```
