let resuleObj = {};
const getSum = (n) => {
    if (n == 1) {
        resuleObj['1'] = 1;
        return 1;
    }
    if (n == 2) {
        resuleObj['2'] = 2;
        return 2;
    }
    if (n == 3) {
        resuleObj['3'] = 4;
        return 4;
    }
    let objN0 = resuleObj[n - 1] ? resuleObj[n - 1] : (resuleObj[n - 1] = getSum(n - 1));
    let objN1 = resuleObj[n - 2] ? resuleObj[n - 2] : (resuleObj[n - 2] = getSum(n - 2));
    let objN2 = resuleObj[n - 3] ? resuleObj[n - 3] : (resuleObj[n - 3] = getSum(n - 3));
    return objN0 + objN1 + objN2;

};