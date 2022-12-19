￼￼
![房间钥匙题提交测试结果_20191119.png](https://pic.leetcode-cn.com/226c4628201f7f1b2d8543b18feeb5c666baa40e57c8531e14ca87d1ba7fe221-%E6%88%BF%E9%97%B4%E9%92%A5%E5%8C%99%E9%A2%98%E6%8F%90%E4%BA%A4%E6%B5%8B%E8%AF%95%E7%BB%93%E6%9E%9C_20191119.png)

别忘了判断房间中钥匙所指向房间是否超范围，否则内存会溢出。

代码：
class Solution {
public:

    void search(vector<vector<int>>& rooms, int rooms_len, int room_hash[], int room_id){
        room_hash[room_id] = 1;
        int room_key_len = rooms[room_id].size();
        if(room_key_len == 0) return;
        
        for(int i = 0; i < room_key_len; i++){
            std::cout << rooms[room_id][i] << " " << rooms_len << endl;
            if(rooms[room_id][i] >= rooms_len || room_hash[rooms[room_id][i]] == 1) continue;
            search(rooms, rooms_len, room_hash, rooms[room_id][i]);
        }
            
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int rooms_len = rooms.size();
        if (rooms_len < 2) return true;
        int *room_hash = new int[rooms_len]();
        search(rooms, rooms_len, room_hash, 0);

        int flag = 1;
        for(int id = 0; id < rooms_len; id++){
            flag *= room_hash[id];
        }
        if(flag == 1) {
            //delete room_hash;
            return true;
        }
        else {
            //delete room_hash;
            return false;
        }
    }
};