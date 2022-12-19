![image.png](https://pic.leetcode-cn.com/df782ff453c4e0e4224b0cdf6e6a93496540a743183d720c0b22ba47daa51c96-image.png)

```
func accountsMerge(accounts [][]string) [][]string {
	eMailNameInfo := make(map[string]string)
	accountInfo := make(map[string][]string)
	buildAccountInfo(accounts, eMailNameInfo, accountInfo)

	emailVisited := make(map[string]bool)

	var dfs func(email string)
	circle := make([]string, 0)
	dfs = func(email string) {
		if visited := emailVisited[email]; visited {
			return
		}
		emailVisited[email] = true
		circle = append(circle, email)
		if otherMails, ok := accountInfo[email]; ok {
			for _, otherMail := range otherMails {
				dfs(otherMail)
			}
		}
	}

	result := make([][]string, 0)
	for k := range accountInfo {
		if visited := emailVisited[k]; visited {
			continue
		}
		circle = make([]string, 0)
		name := make([]string, 0)
		name = append(name, eMailNameInfo[k])
		dfs(k)
		sort.Slice(circle, func(i, j int) bool {
			return circle[i] < circle[j]
		})
		circle = append(name, circle...)
		result = append(result, circle)
	}
	return result
}

func buildAccountInfo(accounts [][]string, eMailNameInfo map[string]string, accountInfo map[string][]string) {
	for _, account := range accounts {
		if len(account) > 1 {
			name := account[0]
			firstMail := account[1]
			eMailNameInfo[firstMail] = name
			if _, ok := accountInfo[firstMail]; !ok {
				accountInfo[firstMail] = account[2:]
			} else {
				accountInfo[firstMail] = append(accountInfo[firstMail], account[2:]...)
			}
			for i := 2; i < len(account); i++ {
				otherMail := account[i]
				eMailNameInfo[otherMail] = name
				if _, ok := accountInfo[otherMail]; !ok {
					accountInfo[otherMail] = append(make([]string, 0), firstMail)
				} else {
					accountInfo[otherMail] = append(accountInfo[otherMail], firstMail)
				}
			}
		}
	}
}
```
