
```
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int reslen = reservedSeats.size();
        
        int cnt = 0; //记录可以安排的家庭个数
        vector<int> res; //这个数组用来装某一行被占座的位置
        unordered_map<int, vector<int>> m;
        vector<int> row; //如果某一行座位被人占了, 那么行号会放到这个数组里
        
        //把有人占座的行的序号放到row数组
        //用unordered_map存储每一行具体被占的位置, 可通过行号获取该行被占的位置
        for(int i = 0; i < reslen; i++){
            if(m.find(reservedSeats[i][0]) != m.end()) m[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
            else{
                 m[reservedSeats[i][0]] = {reservedSeats[i][1]};
                 row.push_back(reservedSeats[i][0]);
            }
        }
        
        //只要遍历有人占座的行能安排多少个家庭就好了
        //cnt29:   记录位置2-9被占的座位的个数
        //cnt2345: 记录位置2-5被占的座位的个数
        //cnt4567: 记录位置4-7被占的座位的个数
        //cnt6789: 记录位置6-9被占的座位的个数
        for(int i = 0; i < row.size(); i++){
            res = m[row[i]];
            int cnt29 = 0;
            int cnt2345 = 0;
            int cnt4567 = 0;
            int cnt6789 = 0;
            for(int j = 0; j < res.size(); j++){
                if(2 <= res[j] && res[j] <= 9){
                    cnt29 += 1;
                    if(2 <= res[j] && res[j] <= 5) cnt2345 += 1;
                    if(4 <= res[j] && res[j] <= 7) cnt4567 += 1;
                    if(6 <= res[j] && res[j] <= 9) cnt6789 += 1;
                }
            }
            //当2-9都没人占的时候, 显然可以安排2个家庭
            if(cnt29 == 0) cnt += 2;
            //当2-5或4-7或6-9其中一个没人占的时候, 只能安排一个家庭, 这里画画图就知道了
            else if(cnt2345 == 0 || cnt4567 == 0 || cnt6789 == 0) cnt += 1;
        }
        //剩下的行因为没人占座所以可以直接安排2个家庭
        cnt += 2*(n-row.size());
        return cnt;
    }
};
```
