
一开始就想到了这个思路：
1. 先过滤0-9 和 a-z 之外的字符。（大写转小写）
2. 两个指针： 一个是下标指针，一个是计数指针
3. 回文的情况只有： 左右两边同时计数，最后达到中点下标，此为true。


```
  public boolean isPalindrome(String s) {
    int len = s.length();
    char[] str = s.toLowerCase().toCharArray();
    char[] li = new char[len];
    int k = 0, flag = 0;
    for(int i =0; i < str.length; i++){
      if (('0' <= str[i] && str[i] <= '9') || ('a' <= str[i] && str[i] <= 'z'))
        li[k++] = str[i];
    }
    for(int i =0; i < k /2; i++){
      if(li[i] == li[k -1 -i])
        flag++;
    }
    return flag == k /2;
  }
```
