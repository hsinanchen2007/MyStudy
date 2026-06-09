class Solution {
public:
bool divisorGame(int N) {
    if (N==1) return false;
    bool res=divisorGame(N-1);
    return !res;
}
};