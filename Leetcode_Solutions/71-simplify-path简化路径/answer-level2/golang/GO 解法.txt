![image.png](https://pic.leetcode-cn.com/df252476fd19f4dc19b87f8bff136385ddc2e87fb18706079964c468e3d357bc-image.png)


### 代码

```golang
func simplifyPath(path string) string {
    sla := "/"[0]
    path = path + "/"

    l := len(path)
    b := []string{}

    // temporary
    t := ""

    for i := 0; i < l; i++ {

        // we got `/`
        if path[i] == sla {

            // we have stuff in `t`
            if len(t) > 0 {

                // push in `b`
                b = append(b, t)
                t = ""

                // process `.`, `..`, `...`, `....` etc
                switch b[len(b) - 1] {
                case ".":
                    b = b[0:len(b) - 1]
                case "..":
                    if len(b) > 1 {
                        b = b[0:len(b) - 2]
                    } else {
                        b = b[0:len(b) - 1]
                    }
                }
            }

            continue
        }

        t = t + string(path[i])
    }

    return "/" + strings.Join(b, "/")
}
```