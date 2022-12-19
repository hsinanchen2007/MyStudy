### 解题思路
- 思路参考官方题解。
- 用更**不**严谨的话来解释。
- 从左往右尝试寻找山脉，**所谓山脉就是数字先增大再减小**。
- **用下标start和end来记录山脉，那么山脉长度就是end-start+1.**
- 找下一个山脉M2的时候，M2的start就是上一个山脉的end，而不是上一个山脉的start加1，从而达到了跳跃的效果。
### 如何寻找一个山脉？
用if和else一步一步确认，毕竟符合山脉的要求还挺严格的。具体见代码注释。
### 代码

```cpp
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size()<3) return 0;
        int ans = 0;
        int start = 0;
        while(start<=A.size()-2){
            int end = start; // end尝试延伸这个山脉
            if(A[end]<A[end+1]){ // 山脉一开始必须是严格上升的，否则直接让start+1,进入下一轮
                while(end+1<A.size() && A[end]<A[end+1]){//一直上升到不再上升为止
                    end++;
                }// 此时end的下一个元素已经不比end指向的元素严格大了
                if(end+1<A.size() && A[end]>A[end+1]){ //山脉要求达到最高点后立刻严格下降
                    while(end+1<A.size() && A[end]>A[end+1]){
                        end++;
                    }// 下降到不在严格下降为止，这个时候start和end所包含的区间就是一座山峰了。
                    ans = max(ans,end-start+1); // 尝试更新ans
                    start = end; // 尝试寻找下一座山脉，这里体现了start的跳跃性，类似与kmp模式匹配那种
                }else{// 如果是平着的，或者到了末尾，就开始下一轮，因为这一轮没有山峰。为什么没有山峰？因为山峰必须要有严格下降，没有就不是山峰。
                    start = end+1;
                    continue;
                }
            }else{
                start++;
            }
        }
        return ans;
    }
};
```