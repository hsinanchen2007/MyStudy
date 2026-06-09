为什么验证字符有效性不使用正则表达式

```
        // 处理字符串为只有数字和字母
        s = s.replaceAll("[^a-zA-Z0-9]","");
        s = s.toLowerCase();
```

