比较菜，太复杂的也不会
读题后知道，回文数，是从左向右和从右向左读起来完全一致的数
所以，只要将整数壹收尾对应的数比较，一致，即为回文串
代码如下
public boolean isPalindrome(int x){
    String str = Integer.toString(x);
    for(int i = 0;i < str.length() / 2;i++){
        if (str.charAt(i) != str.charAt(str.length() -1 -i)){
            return false;
        }
    }
    return true;
}
