
每次先定位到不为空值的左右边界，然后使用二分思想，如果mid的值为空，则向右线性探查，直到不为空。
```java
public int findString(String[] words, String S) {
    if (words == null || words.length == 0) return -1;
    int left = 0, right = words.length-1;
    while (left <= right){
        while (left <= right && words[left].length() == 0)left++;
        while (left <= right && words[right].length() == 0)right--;
        int mid = left + (right-left)/2;
        while (mid < right && words[mid].length() == 0) mid++;
        if (words[mid].equals(S)) return mid;
        else if (words[mid].compareTo(S) > 0) right = mid-1;
        else left = mid+1;
    }
    return -1;
}
```

> 第一次写题解，若有瑕疵，请积极指出，谢谢。
