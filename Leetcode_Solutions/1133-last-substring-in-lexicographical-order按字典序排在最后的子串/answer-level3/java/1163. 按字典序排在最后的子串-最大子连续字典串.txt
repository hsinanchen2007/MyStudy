/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/8/24
 *
 * 解题思路：(最坏情况 O(n*n))
 *
 * 1.O(n) 找出当前最大字符max_char，也就是最大连续字典序列 开头字符
 *
 * 2.再次遍历找出都是max_char开头的字串，并比较大小，将最大字串保存为当前最优解，直到遍历完成退出。如果中途比较到末尾，则退出。推出后max_index ~ s.length() 为最大连续字典序列
 */
```
public String lastSubstring(String s) {

        char[] s_arr = s.toCharArray();
        char max_char = s_arr[0];
        
        int max_index  = -1;
        int cur_index  = -1;

        //寻找最大字符串
        for(int i = 1; i < s.length();i++){
            if(s_arr[i] > max_char){
                max_char = s_arr[i];
            }
        }

        //找出最大字典序连续字串
        for(int i = 0; i < s.length();i++){
            if(max_char == s_arr[i]){ //当前是最大字符,一定是开头
                if(max_index == -1){ //初始化
                    max_index = i;
                }else{ //计入当前
                    cur_index = i;
                }

                if(max_index != -1 && cur_index != -1){ //出现 当前和当前最大都非空,双指针同时后移进行比较
                    int m;
                    int n;
                    for( m = max_index , n = cur_index ; n < s_arr.length; m++ , n++){
                        if(s_arr[m] < s_arr[n]){
                            max_index = cur_index;
                            break;
                        }else if(s_arr[m] > s_arr[n]){
                            break;
                        }
                    }
                    if(n == s_arr.length){ // 如果一直比较到最后 那么直接退出，当前最大即为最优解（减枝）
                        break;
                    }
                }
            }

        }
        return s.substring(max_index,s.length());
    }
```