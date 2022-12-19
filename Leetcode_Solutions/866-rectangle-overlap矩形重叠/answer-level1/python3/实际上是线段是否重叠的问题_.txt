## 解题思路:

1. 将矩形A, B的宽分别投影到x轴, 得到下面的情况
    
    
![a.png](https://pic.leetcode-cn.com/5c6e3b7d9dd22da402b59c0de108166907a0db2a3baae8ebb176f344673cf7f9-a.png)

    线段1和线段2重合的条件是: 线段1长度 + 线段2长度 > 线段0长度

2. 将矩形A, B的高分别投影到y轴, 判断重合的条件和1类似
3. 当步骤1和步骤2判断的结果都是重合时, 那么这两个矩形有重叠

## 欢迎关注公众号, 大家一起学习数据结构和算法, 以及深度学习相关的内容, 原创文章每天分享, 除技术干货还有实习面试经验等
![qrcode.bmp](https://pic.leetcode-cn.com/467aacb8ed9cc079ef1282f0589629e497978eb249aa0371863cff2ae14a0181-qrcode.bmp)
