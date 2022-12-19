所谓的回文字符串，是指具有左右对称特点的字符串，例如 "abcba" 就是一个回文字符串。

使用双指针可以很容易判断一个字符串是否是回文字符串：令一个指针从左到右遍历，一个指针从右到左遍历，这两个指针同时移动一个位置，每次都判断两个指针指向的字符是否相同，如果都相同，字符串才是具有左右对称性质的回文字符串。

<![00123.png](https://pic.leetcode-cn.com/b4db42a921f68fcf304f917f4d302b03d35fe2b548ef1b6e82a001a7e9b1816b-00123.png),![00124.png](https://pic.leetcode-cn.com/7efd986082e3e3d5d0fc42d073fb1da6c3b759f9c7a2590254932221a92034d9-00124.png),![00125.png](https://pic.leetcode-cn.com/66ea8cbeaf196461bd3861109864ad6b49195afb9b80607471ee98c4308e4e9d-00125.png)>

本题的关键是处理删除一个字符。在使用双指针遍历字符串时，如果出现两个指针指向的字符不相等的情况，我们就试着删除一个字符，再判断删除完之后的字符串是否是回文字符串。

在判断是否为回文字符串时，我们不需要判断整个字符串，因为左指针左边和右指针右边的字符之前已经判断过具有对称性质，所以只需要判断中间的子字符串即可。

在试着删除字符时，我们既可以删除左指针指向的字符，也可以删除右指针指向的字符。

<![00126.png](https://pic.leetcode-cn.com/e6050fae8b6883432f97c05b23bf5eda7aff03ec8d988db1316072d56eec4766-00126.png),![00127.png](https://pic.leetcode-cn.com/a6b8ffa612037b61a1cc65df5223078fbc2f002fc6f07d4e53f33a6feb075c3d-00127.png),![00128.png](https://pic.leetcode-cn.com/d4cb1afab503cc541af6fc111fc15bbf7dce7c2de5a5b996611d1247ee0d63b0-00128.png),![00129.png](https://pic.leetcode-cn.com/530fa39cef066cc5ea55a9d3fcca613d37bd0a2b8b273dbdc843068953d43f58-00129.png)>