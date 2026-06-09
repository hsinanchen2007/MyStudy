```
class Solution {
    public void reverseString(char[] s) {
        int j = 0;
        for(int i = s.length - 1; i > 0; i--){
             if(i <= j){//数组元素为奇数个的时候，i = j 停止遍历； 偶数个 i < j 停止遍历
                break;
             }
            swap(s, i, j);//交换元素
            j++;//指针移动
        }
        
    }
    
    private void swap(char[] s, int i, int j){
         char temp = s[i];
         s[i] = s[j];
         s[j] = temp;
    }
}
```


