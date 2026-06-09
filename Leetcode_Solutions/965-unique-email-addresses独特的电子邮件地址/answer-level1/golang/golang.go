```
func numUniqueEmails(emails []string) int {
    m := make(map[string]bool)

	for _, email := range emails {
		var buf bytes.Buffer

		at := false
		plus := false
		for _, s := range email {
			if !at {
				if string(s) == "." {
					continue
				}

				if plus == true && string(s) != "@" {
					continue
				}

				if string(s) == "+" {
					plus = true
				} else {
					if string(s) == "@" {
						at = true
					}
					buf.WriteRune(s)
				}
			} else {
				buf.WriteRune(s)
			}
		}

		e := buf.String()
		if e != "" {
			m[buf.String()] = true
		}
	}

	return len(m)
}
```