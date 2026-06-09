
在看提交记录里用时分布表中看到别人的一份答案如下：
```cpp
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0,lenname = name.length(),lentyped = typed.length();
        while(i<lenname&&j<lentyped){
            if(name[i]!=typed[j]) j++;
            else{
                i++;
                j++;
            }
        }
        return i==lenname;
    }
};
```
面对 name: alex   typed: aaleelx （false）时，会返回true，
对"laiden" "laidenxxxx"这个显然false的用例，它也会返回true
然而submit这份代码能通过所有71个用例测试，这么多用例都没有覆盖到这个点，感觉有点奇怪，记录一下。