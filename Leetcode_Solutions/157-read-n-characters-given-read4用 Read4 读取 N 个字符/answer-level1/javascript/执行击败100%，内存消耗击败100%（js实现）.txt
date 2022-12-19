### 解题思路
主要是题目不太好懂。
read4(buffer);读几个字符到buffer，返回读的数目。
创建buf存储读到的信息，根据题意，buf中字符的个数就是最后应返回的结果。

因此思路是，用read4读取，存到buf中。
读完后，返回buf长度。

于是while(n),
read4读取；
若读到的字数小于4（到最后了），在buf中，插入buffer中内容。
此时若n比实际剩余的小，（比如还有4个字符，但是n是3.此时buf中是4个字符，返回值是4，但我们应取他读到的前三个，于是buffer.slice）
同理若n比实际剩余的大，比如还有2个字符，读了4个，那么我们应该只取前两个。buffer.slice(0,Math.min(n,temp)
然后返回buf长度即是结果
否则
将buf内容放到buffer中，
n-4,
重复上述步骤

最后返回buf长度

### 代码

```javascript
/**
 * Definition for read4()
 * 
 * @param {character[]} buf Destination buffer
 * @return {number} The number of actual characters read
 * read4 = function(buf) {
 *     ...
 * };
 */

/**
 * @param {function} read4()
 * @return {function}
 */
var solution = function(read4) {
    return function(buf, n) {
        let buffer = [];
        while(n){
        let temp = read4(buffer);
        if (n<4||temp<4){
            buf.splice(buf.length,0,...buffer.slice(0,Math.min(n,temp)));
            return buf.length;
        }
        else{
            buf.splice(buf.length,0,...buffer);
            n-=4;
        }}
        return buf.length;
    }
    }



```