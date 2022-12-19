
![image.png](https://pic.leetcode-cn.com/f71f0e7650b8ddcb6cb88fcee34aff85aafcf4a3f330ae6e5f5a3832305ed8e1-image.png)
速度很快  但是占内存
```
   let arr = digits.reverse();


        for (let index = 0; index < arr.length; index++) {
            if (arr[index] + 1 == 10) {
                arr[index] = 0;
                if (index == arr.length - 1) {
                    arr[index + 1] = 1;
                    break;
                }

            } else {
                arr[index] += 1;
                break;
            }

        }
        return arr.reverse()
```