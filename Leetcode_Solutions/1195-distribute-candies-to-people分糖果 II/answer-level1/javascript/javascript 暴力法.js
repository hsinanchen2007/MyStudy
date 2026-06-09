var distributeCandies = function(candies, num_people) {
    const res = new Array(num_people).fill(0);
    let lunci = 0;
    let distributeNum = 0;
    while(candies) {
        for(let i = 0; i < num_people; i++) {
            distributeNum = lunci * num_people + i + 1;
            if(distributeNum >= candies) {
                res[i] += candies;
                return res;
            }
            else {
                res[i] += distributeNum;
                candies -=  distributeNum;
            }
        }
        lunci++;
    }
    return res;
};