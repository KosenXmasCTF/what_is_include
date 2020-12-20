# what is include?
![Genre: Misc](https://img.shields.io/badge/genre-misc-brightgreen?style=for-the-badge)
![Difficulty: Medium](https://img.shields.io/badge/difficulty-Medium-blue?style=for-the-badge)
![Author: iwancof](https://img.shields.io/badge/author-iwancof-lightgrey?style=for-the-badge)

彼は #include の意味がよくわかっていないみたい！
...うまく騙してフラグを取れないかな？

## Files
なし(ssh先だけ)

## Run
```
$ make
$ docker build . -t what_is_include/latest
$ sudo docker run -p 10000:22 --name problem what_is_include/latest
$ ssh guest@localhost -p 10000
		password: guest
```
## writeup
writeup.md を見てください

## Comment
Dockerの使いかたよくわかっていないためDockerfileやコマンドがよくなさそう。
それとsshdの設定もよくわからん。
