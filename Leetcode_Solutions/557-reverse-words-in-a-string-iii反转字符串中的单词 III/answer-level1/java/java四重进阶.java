## 1、初级暴力破解

使用char遍历字符串，判断空格后将记录的上一个单词反转，然后追加到新字符串上。反转的方法是将单词的char顺序遍历倒转。

手写代码行数太长，效率肯定是很低的。时间复杂度达到O(3n), 空间复杂度O(n).

代码：

```java
public String reverseWords(String s) {
    StringBuilder str = new StringBuilder();
    StringBuilder sub = new StringBuilder();
    for (char c : s.toCharArray()){
        if(c!=(" ".charAt(0))){
            sub.append(c);
        }else{
            str.append(reverseString(sub.toString()));
            str.append(" ");
            sub=new StringBuilder();
        }
    }
    str.append(reverseString(sub.toString()));
    return str.toString();
}

public String reverseString(String s) {
    char[] re = new char[s.length()];
    int i=0;
    for (char c : s.toCharArray()){
        re[i]=c;
        i++;
    }
    StringBuilder str = new StringBuilder();
    for (int j=re.length -1;j>=0;j--) {
        str.append(re[j]);
    }
    return str.toString();
}
```

## 2、中级暴力破解

使用String的split方法直接按空格分割单词，使用StringBuilder的reverse方法直接反转单词，时间复杂度减到O(2n).

代码：

```java
public String reverseWords(String s) {
    String[] words = s.split(" ");
    StringBuilder str = new StringBuilder();
    int len=words.length;
    for (int i = 0; i < len; i++){
        str.append(reverseString(words[i]));
        if(i!=len-1) str.append(" ");
    }
    return str.toString();
}

public String reverseString(String s) {
    StringBuilder str = new StringBuilder();
    for (char c : s.toCharArray()){
        str.append(c);
    }
    return str.reverse().toString();
}
```

## 3、高级暴力破解

直接新建new StringBuffer(word)然后反转，使用trim()方法去除字符串尾部空格，时间复杂度降到O(n).

代码：

```java
public String reverseWords(String s) {
    String[] words = s.split(" ");
    StringBuilder str = new StringBuilder();
    int len=words.length;
    for (String word : words){
        str.append(new StringBuffer(word).reverse().toString()).append(" ");
    }
    return str.toString().trim();
}
```

## 4、双指针

不借用Java函数方法，双指针将每个单词反转。char追加到新字符串上。时间复杂度O(2n+logn).

代码：

```java
public String reverseWords(String s) {
    char[] letter = s.toCharArray();
    int left=0;
    int right=0;
    char temp;
    char empty =" ".charAt(0);
    int len=letter.length;
    for (int i = 0; i < len; i++){
        if((i == len -1)||letter [i+1]==empty){
            right = i;
            while (left<right){
                temp=letter[left];
                letter[left]=letter[right];
                letter[right]=temp;
                left++;
                right--;
            }
            left=i+2;
            right=0;
        }
    }
    StringBuilder str = new StringBuilder();
    for (char c : letter){
        str.append(c);
    }
    return str.toString();
}
```

