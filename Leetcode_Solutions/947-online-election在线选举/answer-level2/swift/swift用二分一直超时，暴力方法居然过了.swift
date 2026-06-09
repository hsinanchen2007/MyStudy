一开开始老老实实预处理，然后二分，一直超时，找了题解里其他人的二分，最少的也要`1770ms`，不是很开心。
后来直接把每个时间点的获胜者塞到一个数组里，居然过了，虽然时间是`1600ms`...
```
class TopVotedCandidate {
    var record: [Int: Int] = [:]
    var winnerVotes = 0
    var lastWinner = 0
    var veryWinners = [Int]()
    var firstTime = 0
    init(_ persons: [Int], _ times: [Int]) {
        var i = 1
        winnerVotes = 1
        lastWinner = persons[0]
        record[persons[0]] = 1
        veryWinners.append(persons[0])
        var lastTime = times[0]
        firstTime = lastTime
        while i < persons.count {
            let person = persons[i]
            var t = 0
            while t < times[i] - lastTime - 1 {
                veryWinners.append(lastWinner)
                t += 1
            }
            let vts = (record[person] ?? 0) + 1
            record.updateValue(vts, forKey: person)
            if vts >= winnerVotes {
                winnerVotes = vts
                lastWinner = person
                
            }
            veryWinners.append(lastWinner)
            lastTime = times[i]
            i += 1
        }
        
    }

    func q(_ t: Int) -> Int {
        let idx = t - firstTime
        if idx >= veryWinners.count {
            return veryWinners.last!
        }
        return veryWinners[idx]
    }
}
```