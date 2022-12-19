
#### 执行结果

![1573458662234-image.png](https://pic.leetcode-cn.com/66d45ee0d3b6635fce9eac976230f04e4d80e84e75ad4d47a0bd3cf0269e456b-1573458662234-image.png)


#### 代码如下
```
class Solution {
    public String validIPAddress(String ip) {
        if(validateV4(ip)){
            return "IPv4";
        }
        if(validateV6(ip)){
            return "IPv6";
        }
        return "Neither";
    }
    
    private boolean validateV4(String ip){
        if (null == ip) {
            return false;
        }

        char[] segment = null;
        int segSize = 0;

        int seperatorCount = 0;

        char[] arr = ip.trim().toCharArray();

        for (int count = 0; count < arr.length; count++) {

            char c = arr[count];

            // 只能出现分隔符.和数字
            if (c != 46 && (c < 48 || c > 57)) {
                //ascii : 46->. 48..57->0..9
                return false;
            }

            if (c == 46) {
                // 当前是分隔符

                if(++seperatorCount > 3){
                    return false;
                }

                if (segSize == 0 || null == segment) {
                    // 不能以分隔符开头
                    return false;
                }
                
                if(count == arr.length - 1){
                    // 不能以分隔符结尾
                    return false;
                }

                if(segment[segSize-1] == '.'){
                    // 不能连续两个分隔符
                    return false;
                }

                // 验证分段
                if (!validateSegment(segment, segSize)) {
                    return false;
                }

                // 验证完成，segment置null
                segment = null;

                continue;

            }

            // 重新初始化segment
            if (null == segment) {
                segment = new char[3];
                segSize = 0;
            }

            if (segSize + 1 > 3) {
                // segment不能超过3
                return false;
            }

            segment[segSize++] = c;


            // 最后一个字符 结束再次判断
            if (count == arr.length - 1) {

                if (!validateSegment(segment, segSize)) {
                    return false;
                }

            }

        }

        if(seperatorCount != 3){
            return false;
        }

        return true;
    }
    
        private boolean validateSegment(char[] segment, int segSize) {
        if(segSize == 0){
            return false;
        }
        if (segSize > 1 && segment[0] == '0') {
            // segment不能0开头
            return false;
        }

        Integer checkValue = Integer.valueOf(String.valueOf(Arrays.copyOf(segment, segSize)));

        if (checkValue > 255) {
            return false;
        }

        return true;
    }
    
    public boolean validateV6(String ip){
        if (null == ip) {
            return false;
        }

        StringBuilder segment = null;

        int seperatorCount = 0;

        char[] arr = ip.trim().toCharArray();

        for (int count = 0; count < arr.length; count++) {

            char c = arr[count];

            if (c == ':') {

                if(++seperatorCount > 7){
                    return false;
                }

                if (null == segment) {
                    return false;
                }

                // 验证分段
                if (!validateV6Segment(segment.toString())) {
                    return false;
                }

                // 验证完成，segment置null
                segment = null;

                continue;

            }

            // 重新初始化segment
            if (null == segment) {
                segment = new StringBuilder(4);
            }

            segment.append(c);


            // 最后一个字符 结束再次判断
            if (count == arr.length - 1) {

                if (!validateV6Segment(segment.toString())) {
                    return false;
                }

            }

        }

        if(seperatorCount != 7){
            return false;
        }

        return true;
    }

    private boolean validateV6Segment(String segment){
        if(segment.length() == 0 || segment.length() > 4){
            return false;
        }
        for(char c : segment.toCharArray()){
            if(!((c>='0'&&c<='9')||(c>='a'&&c<='f')||(c>='A'&&c<='F'))){
                return false;
            }
        }
        return true;
    }
}
```

