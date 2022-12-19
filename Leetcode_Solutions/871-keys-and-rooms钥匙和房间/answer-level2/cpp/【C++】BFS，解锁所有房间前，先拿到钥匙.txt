1.初始化所有没有打开的房间
2.BFS获取钥匙
3.开锁房间获取新钥匙
```
/*
 * Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: i love leetcode
 * Author: Nicolas
 * Create: 2019/10/17
 */
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        set<int> lockedRooms;
        initAllLockedRooms(rooms, lockedRooms);
        unlockRooms(lockedRooms, rooms);
        return isAllUnlocked(lockedRooms);
    }

    bool isAllUnlocked(set<int> &lockedRooms)
    {
        if (lockedRooms.empty()) {
            return true;
        }
        return false;
    }

    void unlockRooms(set<int> &lockedRooms, vector<vector<int>>& rooms)
    {
        queue<int> checkQueue;
        checkQueue.push(0);
        while (!checkQueue.empty()) {
            int key = checkQueue.front();
            checkQueue.pop();

            set<int>::iterator finder = lockedRooms.find(key);
            if (finder != lockedRooms.end()) {
                lockedRooms.erase(finder);
                pushAllOtherKeys(rooms, key, checkQueue);
            }
        }
    }

    void initAllLockedRooms(vector<vector<int>> &rooms, set<int> &lockedRooms)
    {
        int roomCount = rooms.size();
        for (int i = 0; i < roomCount; ++i) {
            lockedRooms.insert(i);
        }
    }

    void pushAllOtherKeys(vector<vector<int>> &rooms, int key, queue<int> &checkQueue)
    {
        for (vector<int>::const_iterator iter = rooms.at(key).begin();
                iter != rooms.at(key).end();
                ++iter) {
            checkQueue.push(*iter);
        }
    }

};
```
