#include <bitset>

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        constexpr int MASK_LEFT = 0b1000011111;
        constexpr int MASK_RIGHT = 0b1111100001;
        constexpr int MASK_MID = 0b1110000111;

        unordered_map<int, int> seats;
        for (auto &reserve : reservedSeats) {
            // std::cout << reserve[0] << " " << reserve[1] << std::endl;
            seats[reserve[0]] |= (1 << (reserve[1] - 1));
        }

        int ret = 2 * (n - seats.size());
        bool mid;
        for (auto &pair : seats) {
            // std::cout << pair.first << " " << bitset<10>(pair.second) << std::endl;
            mid = true;
            if ((pair.second | MASK_LEFT) == MASK_LEFT) {
                ret++;
                // std::cout << pair.first << " " << ret << std::endl;
                mid = false;
            }
            if ((pair.second | MASK_RIGHT) == MASK_RIGHT) {
                ret++;
                // std::cout << pair.first << " " << ret << std::endl;
                mid = false;
            }
            if (mid && (pair.second | MASK_MID) == MASK_MID) {
                ret++;
                // std::cout << pair.first << " " << ret << std::endl;
            }
        }
        return ret;
    }
};