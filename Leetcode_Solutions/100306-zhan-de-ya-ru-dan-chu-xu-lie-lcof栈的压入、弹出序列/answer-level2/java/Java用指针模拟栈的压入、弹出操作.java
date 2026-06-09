class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int i = 0, j = 0, size = pushed.length;
        while(size > 0){
            //如果不相等，一直入栈
            while(i < size && pushed[i] != popped[j]){
                i++;
            }
            //i==size说明元素全部入栈，也没有找到和弹出序列下一个值相同的元素
            if(i == size){
                return false;
            }
            //后面的元素覆盖当前弹出元素，模拟栈顶元素弹出
            if(i < size - 1){
                for(int m = i; m < pushed.length-1; m++){
                    pushed[m] = pushed[m+1];
                }
            }
            if(i>0) i--;
            size--;
            j++;
        }
        return true;
    }
}