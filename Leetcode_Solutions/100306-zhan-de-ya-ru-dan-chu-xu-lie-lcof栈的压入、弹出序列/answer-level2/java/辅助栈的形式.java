### 解题思路
执行用时 : 1 ms , 在所有 Java 提交中击败了 99.50% 的用户 
内存消耗 : 39.3 MB , 在所有 Java 提交中击败了 100.00% 的用户
### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        if(pushed.length==0 && popped.length==0){
            return true;
        }
        if(popped.length==0 || pushed.length==0){
            return false;
        }
        int i = 0;
        int j=0;
        LinkedList<Integer> temp = new LinkedList();
        while(i<pushed.length){
            int value = pushed[i];
            if(value==popped[j]){
                //和期望出栈的数字相同，则继续查看没有出栈的数据是否可以匹配上
                j++;
                while(temp.size()!=0 && temp.getLast()==popped[j]){
                    temp.removeLast();
                    j++;
                }
            }else{
                //匹配不上 加入栈中
                temp.add(value);
            }
            i++;
        }
        if(temp.size()==0){
            return true;
        }else{
            // while(j<popped.length){
            //     int value = popped[j];
            //     if(value!=temp.getLast()){
            //         return false;
            //     }
            //     temp.removeLast();
            //     j++;
            // }
            // return true;
            return false;
        }
    }

}
```