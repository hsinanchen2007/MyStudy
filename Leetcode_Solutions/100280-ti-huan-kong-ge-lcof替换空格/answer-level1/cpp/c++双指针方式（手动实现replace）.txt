![image.png](https://pic.leetcode-cn.com/5c7a38f5d8d592a2ceb10cd45111b79b000484531eb181f658016a29b52e42c5-image.png)



![image.png](https://pic.leetcode-cn.com/16a71b5dd804f27fa720f3af8e1fca482e364ba112f4d2919923e38d28164228-image.png)

查看相关，发现并没有人仔细的去实现过c++的双指针方式完成题目要求，丧失题目原本的含义

代码：
string replaceSpace(string s)
{
    int rawLength = s.length();
    int numBlank = 0;
    if (rawLength == 0){
        return s;
    }
    
    for(int i = 0; i < rawLength; i++){
        if (s[i] == ' '){
            numBlank++;
        }
    }
    
    int p2 = rawLength + 2 * numBlank;
    int p1 = rawLength;
    char string[p2+1];

    while (p1 > -1 && p2 >p1)
    {
        if(s[p1] == ' '){
            string[p2--] = '0';
            string[p2--] = '2';
            string[p2--] = '%';
        }
        else{
            string[p2--] = s[p1];
        }
        p1--;
    }
    while (p1 > -1){
        string[p2--] = s[p1--];
    }
    
    printf("%s",string);
    return s;
}

这一块原本参数应该是不定长的char数组，但是题目做了一点改动，为了避免内存泄漏这一类的错误，
申请数组string空间的时候，使用极其不规范的动态申请方式，不过还是能够过，不建议学习使用。
另外注意下在原数组本身移动操作和复制操作的区别，双指针同时从后向前移动，更符合本人的思考习惯，也可以
不同向使用双指针