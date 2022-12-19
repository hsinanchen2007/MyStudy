var romanToInt = function(s) {
    let romeNum = {
        'I': {
          arr: [],
          num: 1,
        },
        'V': {
          arr: ['I'],
          num: 5,
        },
        'X': {
          arr: ['I'],
          num: 10,
        },
        'L': {
          arr: ['X'],
          num: 50,
        },
        'C': {
          arr: ['X'],
          num: 100,
        },
        'D': {
          arr: ['C'],
          num: 500,
        },
        'M': {
          arr: ['C'],
          num: 1000,
        },
      }
      let n = 0
      let arr = s.split('')
      arr.reduce((v1, v2) => {
        n += (romeNum[v1].num < romeNum[v2].num && romeNum[v2].arr.indexOf(v1) != -1) ? -romeNum[v1].num : romeNum[v1].num
        return v2
      })
    return n + romeNum[arr.pop()].num
    
};