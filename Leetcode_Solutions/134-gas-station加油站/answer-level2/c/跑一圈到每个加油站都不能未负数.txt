int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    if (gasSize != costSize || gasSize == 0 || costSize == 0) {
        return -1;
    }
    int start = 0;
    int left = 0;
    int end = start;
    while (true) {
        left += (gas[end] - cost[end]);
        if ( left >= 0 ) {
            end = (end + 1) % gasSize;
            if (end == start) {
                return start;
            }
        }else {
            end = (end + 1) % gasSize;
            if (start >= end){
                return - 1;
            }
            left = 0;
            start = end;
        }
    }
}