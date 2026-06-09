1. 每个数从依次与运算 128 64 32 16，计算这个unicode多少位，计入count；
2. 假如目前count为0，不允许有10开头的
3. 减去自己本身，count-1，之后每遍历一个count-1
4. count没归零之前，必须是10开头，不是的话返回false
```
    
    public boolean validUtf8(int[] data) {
        int n = data.length;
        if (n == 0) {
            return true;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                int validate_bit = 128;
                while(validate_bit >= 16 && (data[i] & validate_bit) == validate_bit) {
                    count++;
                    validate_bit >>= 1;
                }
                if ((data[i] & validate_bit) == validate_bit) {
                    return false;
                }
                if (count == 1) {
                    return false;
                }
                if (count > 0) {
                    count--;
                }
            } else {
                if ((data[i] & 128) != 128 || (data[i] & 64) == 64) {
                    return false;
                }
                count--;
            }
        }
        if (count == 0) {
            return true;
        } else {
            return false;
        }
    }

```
