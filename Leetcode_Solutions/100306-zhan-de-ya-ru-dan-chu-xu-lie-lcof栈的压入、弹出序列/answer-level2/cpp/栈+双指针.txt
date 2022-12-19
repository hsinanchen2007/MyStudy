![微信图片_20200311175554.png](https://pic.leetcode-cn.com/355937fb69d051a2446fcf3a02ed3510c7c38738523b5a857cf7ffaa9a3d2bf9-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200311175554.png)
时间复杂度：O(N)，需要遍历序列一遍
空间复杂度：O(1)
```
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        //需要一开始对两个序列做初始化的检查
        if(pushed.size() != popped.size()){
            return false;
        }
        if(pushed.size() == 0 && popped.size() == 0){
            return true;
        }

        stack<int> seq;
        seq.push(pushed[0]);
        int i = 0, j = 0;
        while(j < popped.size()){       //这里利用poped序列来控制循环
            if(seq.empty()){    //应对的情况是第一个进栈的元素被弹出
                seq.push(pushed[++i]);
            }
            int temp = seq.top();
            if(temp == popped[j]){
                seq.pop();                
                j++;
            }
            else{
                i++;
                if(i >= pushed.size()){     //会出现i>=pushed.size()的情况
                    break;
                }
                seq.push(pushed[i]);
            }
        }
        return seq.empty();
    }
};
```
