
```  java
class Solution {
    public int removeDuplicates(int[] array) {
        int L = 0;
        int R = L+1;
        boolean flag = true;
        while(R < array.length){
            if(array[L] < array[R]){
                L++;
                array[L] = array[R];
                R++;
                flag = true;
            }else if(array[L] == array[R] && flag == true){
                L++;
                array[L] = array[R];
                R++;
                flag = false;
            }else
                R++;
        }
        return L+1;
    }
}
```