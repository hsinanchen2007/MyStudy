### 解题思路
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;本题的关键在于如何从滑动窗口中动态获取每一个最大值。这里我们可以考虑维护一个**单调队列**，简而言之就是始终保证队列中的元素均处在当前滑动窗口范围内且元素由队头至队尾呈单调递减的状态。那么这个单调队列需要什么操作呢？
>- 队尾插入当前元素；
>- 队头弹出最大值，原因在于**单调**队列的队头元素一定是当前滑动窗口的最大值；
>- 队尾弹出元素，原因在于为维持单调队列的**单调性**(递减)，要先判断待插入元素与队尾元素的大小关系，如果待插入元素大于队尾元素，说明队尾元素肯定不会是滑动窗口的最大值，所以要先将队尾元素弹出再将插入元素进队；
>- 队头弹出已经不属于当前滑动窗口范围的元素。为什么会从队头弹出而不会从队尾弹出不属于窗口的元素？原因在于上一个队尾弹出操作中，**为了维持单调性，不可能成为最大值的元素早已经被弹出**，所以说剩下可能需要弹出的元素只有队头的窗口最大元素。同时也可以保证最大值的实时更新，如果没有这一步操作，当遇到整个数组的最大值时，滑动窗口的最大值肯定不会再变化(甚至不用等到那时候，超出窗口大小的一定范围内的数组最大值也会导致滑动窗口最大值在那一段时间不变)。

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;由上述操作我们发现队头队尾均需要弹出元素，为应对这些问题，我们可以考虑使用双端队列`deque`数据结构(`c++ stl`)。

<br/>


### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size() == 0 || k == 0)
            return result;
        
        //使用双端队列，便于从队尾删除不可能为滑动窗口最大值的候选元素，
        //另外滑动窗口最大值总出现在队头
        deque<int> record;          //存储数组下标,便于判断队头元素是否处于当前滑动窗口范围内

        for(int i = 0; i < nums.size(); i++){
            if(i < k){  //填满第一个滑动窗口
                while(!record.empty() && nums[i] > nums[record.back()])
                    record.pop_back();    //如果队尾元素小于数组元素，说明队尾元素肯定不是滑动窗口的最大值，因此从队尾弹出
                record.push_back(i);
            }
            else{      //窗口开始滑动
                result.push_back(nums[record.front()]);    //从队头获取最大值
                while(!record.empty() && nums[i] > nums[record.back()])
                    record.pop_back();    
                if(!record.empty() && record.front() <= (i - k))
                    record.pop_front();   //如果当前队头的最大值已不在当前滑动窗口范围内，从队头弹出
                record.push_back(i);
            }    
        }
        result.push_back(nums[record.front()]);  //根据循环的过程，最后一个最大值仍未入容器
        return result;
    }
};
```

<br/>

>如果有错误或者不严谨的地方，请务必给予指正，十分感谢。
