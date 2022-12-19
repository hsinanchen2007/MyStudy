class Solution {
    public void reverseString(char[] s) {

        //定义两个指针i,j；分别指向数组的前半部分，后半部分
        //让s[i] 与 s[j] 互换位置
        for(int i = 0,j = s.length -1; i< s.length/2; i++,j--){
            //前半部分元素
            char p = s[i];
            //后半部分元素
            char l = s[j];

            s[i] = l;
            s[j] = p;

        }
       

    }
}