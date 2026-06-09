执行用时 : 3 ms , 在所有 Java 提交中击败了 97.22% 的用户
内存消耗 : 38.9 MB , 在所有 Java 提交中击败了 100.00% 的用户

第一次写题解，因为新题加题解较少，提交记录结果又不错，放出来给各位参考，希望各位大佬指点一下代码中的问题，一起讨论

主要思路是，
1： 从最后一位开始相加，如果当前位的两个数相加，再加上进位，可能的结果一共有 -1 0 1 2 3
2： 根据结果，得到当前位的值，和进位的值
3： 将当前位的值赋值给ret数组，进位的值用于下次相加
4： 每个数组的index 都向左移一个，循环步骤1
5： 当首位是0 并且数组长度不是1的时候，一直调用removeLeadingZero 函数，删除无用的0.

至于进位为什么会有 -1 ，我在纸上通过一些演算，发现如果 当前的位是2（1+1） 的话，实际上是给高位减了1，因此进位会有-1的情况
进位为1的时候，实际上是0 -1 = -1 的时候，实际上当前位temp = 1 并且会让高位进1

源码
```
class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        int arr1Len = arr1.length;
        int arr2Len = arr2.length;
        
        int ret[] = new int[Math.max(arr1Len,arr2Len) + 2];
        int retLen = ret.length;
        //start openration from arr1.length -1 and arr2.length -1, output retLen 
        int temp = 0;
        int carry = 0;
        retLen --;
        while(retLen >= 0){
            
            //handle different length situation;
            if(arr1Len > 0 && arr2Len >0)
                temp = arr1[arr1Len-1] + arr2[arr2Len-1] + carry;
            else if(arr1Len <= 0 && arr2Len >0)
                temp = 0 + arr2[arr2Len-1] + carry;
            else if(arr1Len > 0 && arr2Len <= 0)
                temp = arr1[arr1Len-1] + 0 + carry;
            // both are 0
            else
                temp = 0 + 0 + carry;
            
            switch(temp){
                case 0:
                    ret[retLen] = 0;
                    carry = 0;
                    break;
                case 1:
                    ret[retLen] = 1;
                    carry = 0;
                    break;
                case 2:
                    ret[retLen] = 0;
                    carry = -1;
                    break;
                case 3:
                    ret[retLen] = 1;
                    carry = -1;
                    break;
                case -1:
                    ret[retLen] = 1;
                    carry = 1;
                    break;
            }
            
            arr1Len --;
            arr2Len --;
            retLen --;
            
            
            
        }
        
        
        
        //handle zero case:
        while(ret[0] == 0 && ret.length != 1) {
            ret = removeLeadingZero(ret);    
        }
        
        
        
        return ret;
        
    }
    
    public int[] removeLeadingZero(int[] ret){
        //all zero flag
        int flag = 1;
        
        //Handle leading 0, if exist, remove it, possible situation, ret[0] and ret[1]
        if(ret[0] == 0 && ret[1] == 0){
            int newRet[] = new int[ret.length - 2];
            
            for(int i =0 ; i < newRet.length ; i++ ){
                newRet[i] = ret[i+2];
                // check if all 0 
                if(newRet[i] != 0){
                    flag = 0;
                }
            }
            
            if(flag == 1){
                newRet = new int[1];
                newRet[0] = 0;
            }
            
            return newRet;
        }
        else if(ret[0] == 0 && ret[1] != 0){
            int newRet[] = new int[ret.length - 1];
            
            for(int i =0 ; i < newRet.length ; i++ ){
                newRet[i] = ret[i+1];
            }
            
            return newRet;
        }
        else{
            return ret;
        }
        
            
    }
}
```
