这个题目我个人理解，是想考察设计一些通用API。 设计API时，要对可能的输入做一些假设。

比如：输入参数为(buf, n) 那么对于调用者，可能会用如下的方式：
··
char buf[1000];
f.read(buf, 1000);
··

也就是说，我们应该保证代码不会对buf中，下标超过n的地方进行读写。

还有一点就是，如果是现实中的读文件，会用到IO，消耗很大。所以对于文件的读，我们应保证次数最少。 也就是说，如果某次读取发现已经eof了（read4返回值小于4），应该不能再有读操作了。

除此之外，就是一些简单能看出来的逻辑： 如果文件大小<n，则返回全部文件，返回值为文件大小。否则返回前n个字符，返回值为n。

所以，虽然题目没说，但是作为api开发者，还是要做一些综合考虑的。 （个人的一个实现，权当抛砖引玉吧）

··
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        
        int needBytes = n;
        int curIdx = 0;
        char internalBuf[4];
        bool fileEnd = false;
        while (true) {
            int bytes = read4(internalBuf);
            fileEnd = bytes < 4;
            int idx = 0;
            while (needBytes > 0 && idx < bytes) {
                buf[curIdx++] = internalBuf[idx++];
                --needBytes;
            }
            if (needBytes == 0 || fileEnd) {
                break;
            }
        }
        return curIdx;
    }
};
··
