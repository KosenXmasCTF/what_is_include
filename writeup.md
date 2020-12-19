# writeup

渡せるファイル名が短いし、たとえ長くても何もできなさそうに見えるが、実はシェルが取れる。

まず、#include に </dev/tty> を渡す。そうするとコンパイル時に標準入力を見に行くので、コンパイル中に処理が止まったように見える。
次に、mainで呼ばれているprintfを書き換える。
void printf(char b[]) { system("/bin/sh"); } 
とか入れておく。もちろんgccはEOFまで読むので、Ctrl-D を入力して処理を終了する。すると書き換えられたprintfがshellを呼んでflagが見れる。


