# 45. 跳跃游戏 II
# 数组长度小于等于1时返回0！！！！！
其他就循环找下一步中最好的情况（下一步位置+下一步可走长度）最大。
```
class Solution {
public:
    int jump(vector<int>& nums) {
    	if( nums.size <= 1 ){
        	return 0;
        }

        int end = nums.size()-1;
        int position = 0;
        int step = 0;

        while(1){
            ++step;
        	if( position + nums[position] >= end ){
        		break;
        	}

        	int next_position = position;
        	for( int i = position+1; i <= position+nums[position]; ++i ){
        		if( (i+nums[i]) >= (next_position+nums[next_position]) ){
        			next_position = i;
        		}
        	}

        	position = next_position;
        
        }
        return step;
    }
};
```
