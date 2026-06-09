**二分法的重点是边界条件的判断**

**特殊情况：**如果`letters[0] > target || letters[letters.length - 1] <= target`说明`letters[0]`就是我们需要查找的字符

首先取`mid = left + (right + left) / 2;`

如果`letters[mid] == target`，由于是有序的数组，说明需要在右边查找，`left=mid+1`;

如果`letters[mid] < target`，由于是有序的数组，说明需要在右边查找，`left=mid+1`;

当`letters[mid] > target`,需要分情况讨论，如果`letters[mid - 1] <= target`，说明`letters[mid]`就是我们需要查找的字符，返回即可。否则，我们需要继续在左边查找，`left=mid-1`
```
public static char nextGreatestLetter(char[] letters, char target) {
    if (letters[0] > target || letters[letters.length - 1] <= target)
        return letters[0];
    int left = 1, right = letters.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (letters[mid] <= target)
            left = mid + 1;
        else {
            if (letters[mid - 1] <= target)
                return letters[mid];
            else right = mid - 1;
        }
    }
    return ' ';
}
```
`执行用时 :
1 ms
, 在所有 Java 提交中击败了
97.00%
的用户

内存消耗 :
43.5 MB
, 在所有 Java 提交中击败了
73.48%
的用户`
