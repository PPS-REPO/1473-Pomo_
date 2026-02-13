#include "testlib.h"
using namespace std;

int main(int argc, char** argv) {
    setName("pomodoro score");
    registerTestlibCmd(argc, argv);

    const string TRI = "△"; // "△" (U+25B3) in UTF-8

    string name = inf.readWord();
    int expect = 0;

    while (!inf.seekEof()) {
        string t = inf.readWord();
        if (t == "O") expect += 3;
        else if (t == "△") expect += 2;
        else if (t == "X") expect += 1;
        else quitf(_fail, "Invalid token in input: '%s'", compress(t).c_str());
    }

    string outName = ouf.readWord();
    if (outName != name)
        quitf(_wa, "Name differs - expected: '%s', found: '%s'",
              compress(name).c_str(), compress(outName).c_str());

    int outScore = ouf.readInt();
    if (outScore != expect)
        quitf(_wa, "Score differs - expected: %d, found: %d", expect, outScore);

    ouf.skipBlanks();
    if (!ouf.seekEof()) quitf(_wa, "Participant output contains extra tokens");

    quitf(_ok, "%s %d", compress(name).c_str(), expect);
}
