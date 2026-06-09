难倒是不难，但有两个地方需要注意：

1. 最终要算的是哪个 triple 最受用户欢迎（被**不同的用户**访问的次数最多）。这里算访问数的时候，来自同一个用户的两个相同的 triple 只能算一个。

    例如，用户访问了页面 `[A, B, A, A]`，这里能生成的 triple 包含两个 `ABA`，但最终看哪个 triple 次数最多时，来自同一个用户的只算一次。
2. 自定义 comparator 的时候不要把代码写错。。

```c++
class VisitRecord {
public:
    VisitRecord(int timestamp, const string& website) {
        this->timestamp = timestamp;
        this->website = website;
    }

    static bool cmp(const VisitRecord& a, const VisitRecord& b) {
        return a.timestamp < b.timestamp;
    }

    int timestamp;
    string website;
};

class Triple {
public:
    Triple(const string& s1, const string s2, const string s3) {
        first = s1;
        second = s2;
        third = s3;
    }

    // Lexicographically ascending order.
    static bool cmp(const Triple& a, const Triple& b) {
        if (a.first == b.first) {
            if (a.second == b.second) {
                return a.third < b.third;
            } else {
                return a.second < b.second;
            }
        } else {
            return a.first < b.first;
        }
    }

    string first;
    string second;
    string third;
};


class Solution {
public:
    typedef unordered_map<string, vector<VisitRecord>> UserToVisitRecords;
    typedef map<Triple, int, decltype(Triple::cmp)*> TripleFreqDict;

    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        // Build a map from username to his visiting sequence
        // "John": [A, B, A, D],
        // "Lee": [C, A, B],
        // ...
        UserToVisitRecords user2visits;
        int size = username.size();
        for (int i = 0; i < size; ++i) {
            auto findSeq = user2visits.find(username[i]);
            if (findSeq == user2visits.end()) {
                user2visits.insert(findSeq, {username[i], {VisitRecord(timestamp[i], website[i])}});
            } else {
                findSeq->second.push_back(VisitRecord(timestamp[i], website[i]));
            }
        }

        // For each user's visiting sequence, generate all possible triples,
        // and keep track of the frequencies of those triples.
        TripleFreqDict tripleFreq(&Triple::cmp);
        for (auto it : user2visits) {
            auto& seq = it.second;
            sort(seq.begin(), seq.end(), VisitRecord::cmp);
            // permutate triples
            permutate(seq, &tripleFreq);
        }

        // Find the triple whose freq is the largest.
        using PairType = pair<Triple, int>;
        auto maxTripleAndFreq = max_element(
            tripleFreq.begin(), tripleFreq.end(),
            [] (const PairType& p1, const PairType& p2) {
                return p1.second < p2.second;
            }
        );
        const Triple& bestTriple = maxTripleAndFreq->first;
        return {bestTriple.first, bestTriple.second, bestTriple.third};
    }

    // Generate valid permutations from `seq`, deduplicate them, and update
    // the frequency dict `dest`.
    void permutate(const vector<VisitRecord>& seq, TripleFreqDict* dest) {
        if (seq.size() < 3) return;

        set<Triple, decltype(Triple::cmp)*> dedupedTriples(Triple::cmp);
        for (auto it1 = seq.begin(); it1 < seq.end(); ++it1) {
            for (auto it2 = it1 + 1; it2 < seq.end(); ++it2) {
                for (auto it3 = it2 + 1; it3 < seq.end(); ++it3) {
                    // do insertion
                    Triple triple(it1->website, it2->website, it3->website);
                    dedupedTriples.insert(triple);
                }
            }
        }

        for (auto& it : dedupedTriples) {
            auto findTriple = dest->find(it);
            if (findTriple == dest->end()) {
                dest->insert(findTriple, {it, 1});
            } else {
                findTriple->second += 1;
            }
        }
    }
};
```