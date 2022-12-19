    解题要求：
        要求从第一个位置自主选择不超过元素值的步数，到达选择的元素之后继续向后跳，能到最后一个元素则返回true，否则返回false；
    解题思路：
        1.从倒数第二个元素[i=length-2]判断是否能够到达终点元素（最后一个元素的值已经不重要）；
        2.不能的话则继续往前找，找到能够到达终点元素的则把该元素设置为终点元素；
        3.循环1,2步，直到到达第一个元素[i=0]也满足到达此时的终点元素则返回true；否则返回false；
    运行结果：
        执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
        内存消耗 :38.3 MB, 在所有 Java 提交中击败了94.98%的用户
```
public boolean canJump(int[] nums) {
        if (nums.length==1){
            return true;
        }
        int index = nums.length-2;
        int endIndex = nums.length-1;
        while (index>=0){
            if (nums[index]>=endIndex-index){
                endIndex = index;
                if (index<=0){
                    return true;
                }
            }
            index--;
        }
        return false;
    }
```
