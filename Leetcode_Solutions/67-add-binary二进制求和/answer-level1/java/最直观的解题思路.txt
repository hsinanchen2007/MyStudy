class Solution {
    public String addBinary(String a, String b) {
        int alen = a.length();
        int blen = b.length();
        int jinwei = 0;
        StringBuffer result = new StringBuffer();//用来接收最终结果
        while(alen>0 || blen>0) {
            int sum = 0;
            sum += jinwei;//这里的sum等于进位 + a字符串一位 + b字符串一位

            if(alen>0) {
               String aLastStr = a.substring(alen-1, alen);//从后往前依次截取一位
                int aLastInt = Integer.parseInt(aLastStr);//将其变成int类型数据
                sum += aLastInt;//sum加上a字符串的一位
                alen--;//截取完一位后，向前滚动
            }
            //如果某个字符串算完了，另一个没算完，自然也不会算到算完的那个字符串

            if(blen>0){//处理b字符串也是同样的道理
                String bLastStr = b.substring(blen-1, blen);
                int bLastInt = Integer.parseInt(bLastStr);
                sum += bLastInt;
                blen--;
            }

            switch(sum) {//sum的结果分成四种情况，依次是0,1,2,3 这里分情况讨论
                case 2:
                    jinwei = 1;
                    result.append("0");
                    break;
                case 3:
                    jinwei = 1;
                    result.append("1");

                    break;
                default:
                    jinwei = 0;
                    result.append(sum);
            }
        }

        if(jinwei == 1) {//如果最后进位是1的话，还要添加到最高位；如果最后进位是0的话，就不需要添加
            result.append("1");
        }

        return result.reverse().toString();//最后，结果翻转下返回
    }
}