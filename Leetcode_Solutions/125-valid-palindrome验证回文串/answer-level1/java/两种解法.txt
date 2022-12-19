一：利用正则，先去除不是字母和数字的字符。接着把转换后的字符串和该字符串的反转比较，如果一致就是回文串。
```
    String convert = s.replaceAll("[^\\dA-Za-z]", "");
    return convert.equalsIgnoreCase(new StringBuilder(convert).reverse().toString());
```
![1.JPG](https://pic.leetcode-cn.com/c19ba5891fc536ed4607432121339c7606802e5772cef95f72b608142fb8f7c1-1.JPG)

二：把字符串首尾是字母和数字的字符比较，如果一致就是回文串。
```
    if (s.length() == 0) {
        return true;
    }
    char[] convert = s.toLowerCase().toCharArray();
    int left = 0, right = convert.length - 1;
    while (left < right) {
        if (!(convert[left] <= 'z' && convert[left] >= 'a') && !(convert[left] <= '9' && convert[left] >= '0')) {
            left++;
            continue;
        }
        if (!(convert[right] <= 'z' && convert[right] >= 'a') && !(convert[right] <= '9' && convert[right] >= '0')) {
            right--;
            continue;
        }
        if (convert[left] != convert[right]) {
            return false;
        }
        left++;
        right--;

    }
    return left == right || convert[left] == convert[right];
```
![捕获.JPG](https://pic.leetcode-cn.com/2aa6a2bb262028119397cb64e6bbdaba6e777b76a6794d8041de036c7584c6b5-%E6%8D%95%E8%8E%B7.JPG)


