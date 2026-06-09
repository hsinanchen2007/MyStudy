我跟你讲，这招绝对暴力

代码：
```
class Solution {
public:
    bool isPowerOfTwo(int n) {
        switch(n) {
            case 1:
            case 2:
            case 4:
            case 8:
            case 16:
            case 32:
            case 64:
            case 128:
            case 256:
            case 512:
            case 1024:
            case 2048:
            case 4096:
            case 8192:
            case 16384:
            case 32768:
            case 65536:
            case 131072:
            case 262144:
            case 524288:
            case 1048576:
            case 2097152:
            case 4194304:
            case 8388608:
            case 16777216:
            case 33554432:
            case 67108864:
            case 134217728:
            case 268435456:
            case 536870912:
            case 1073741824:return true;
            default:return false;
        }
    }
};
```
