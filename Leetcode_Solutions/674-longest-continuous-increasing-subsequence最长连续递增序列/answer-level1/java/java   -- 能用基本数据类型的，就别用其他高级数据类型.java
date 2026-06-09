思路：遍历一遍数组，找到局部最大，从局部最大的比较得到全局最大；
同样的思想，两种数据结构，数组1S ，Stack 20S；看2S的算法好像就多了一个Math.min(）类似这样的方法；

代码如下：
执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :37.8 MB, 在所有 Java 提交中击败了93.62%的用户
```
       // 直接用数组来做这个事情
        int n = nums.length;
        int max = 1;
        int currentMax = 1;
        if(n > 1){
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                currentMax++;
            }else{
                if(currentMax > max){
                    max = currentMax;
                }
                currentMax = 1;
            }
        }
            if(currentMax > max){
            max = currentMax;
            }
        
        return max;
        }else{
            return n;
        } 
```
使用栈这种高级数据结构的情况 耗时20 ms	内存42.4 MB

```
    Stack <Integer> data = new Stack<>();
        int n = nums.length;
        int maxLength = Integer.MIN_VALUE;
        for(int i = 0; i < n; i++){
            if(data.empty()){
                data.push(nums[i]);
            }else{
                if(nums[i] > data.peek()){
                    data.push(nums[i]);
                }else{
                    if(data.size() > maxLength){
                        maxLength = data.size();
                    }
                    data.clear();
                    data.push(nums[i]);
                }
            }
            if(i == n-1){
                 if(data.size() > maxLength){
                        maxLength = data.size();
                    }
            }
        }
        if(maxLength == Integer.MIN_VALUE){
            maxLength = data.size();
        }
        
        return maxLength;
```



