# <!-- 暴力题解,虽然效率不高,但可以看一下我的思路 -->
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> list = new ArrayList<>();
//         循环从left到right
        for(int i = left;i<=right;i++){
            int num;
            int jjj=0;
//             把整型int转换成字符串String
            String s = String.valueOf(i);
//             循环left的位数
            for(int j = 0;j<s.length();j++){
//                 把字符转换成数组,再编程正常对应的数字(利用ascii表)
                int iii = s.charAt(j)-48;
//                 防止出现异常(0不能作为除数)
                if(iii !=0){
                    num = i%iii;
                    if(num != 0){
                        break;
                    }else{
                        ++jjj;
//                         只有数字的所有位的数都能被整除才可以添加到集合中
                        if(jjj == s.length()){
                            list.add(i);
                        }
                    }
                }
            }

        }
        return list;
    }
}