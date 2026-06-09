    public:
    bool judgeCircle(string moves) {
        map<char, int> move = { {'L', 0}, {'R', 0}, {'U', 0}, {'D', 0} };
        int len = moves.length();
        if(len%2)
           return false;
        for(int i = 0; i < len; i++)
            move[moves[i]]++;
        if((move['L'] == move['R']) && (move['U'] == move['D']))
            return true;
        return false;
    }