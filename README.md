# AdventBox

Ein Projekt des [CoderDojo Potsdam](https://coderdojopotsdam.github.io/) zum gemeinsamen Basteln und Programmieren in der Adventszeit.

![Schaubild AdventBox](box.jpg)

Die Box bietet eine Verkleidung für einen eigenen elektrischen Adventskranz.
Die vier Kerzen des Adventskranzes lassen sich mittels des Tasters nacheinander anschalten.

Auch wenn der Arduino vom Strom genommen wurde und wieder angesteckt wird, leuchtet die gleiche Anzahl Kerzen. So kannst du bequem die Wochen bis Weihnachten zählen.

## Materialien

- Arduino Nano oder ähnlicher Microcontroller
- 1 Breadboard
- 4 LEDs in der Farbe eurer Wahl
- 4 Widerstände 220 Ohm
- 1 Widerstand 100 kOhm
- 1 Taster
- diverse Jumperkabel oder Kabelbrücken

Außerdem zur Verschönerung:

- Holz für die Box
- Einen 3D-gedruckten Adventskranz
- Aus Acryl geschnittene Kerzen

## Anleitung

1. Zuerst baust du aus [Holz](Lasercuttervorlagen/) und [Acryl](kerzen.svg) die Box eures Adventskranzes.
2. Verbinde zunächst eine LED mit einem Widerstand und deinem Arduino. Lasse die LED blinken und überprüfe so, dass du deinen Arduino ansteuern kannst und alles funktioniert.
3. Nun steckt ihr nach Schaltplan (siehe unten) auf dem Breadboard alle Komponenten zusammen.

|![Logische Schaltung](Schaltplan_Breadboard_Logisch.jpg)|![Schaltung auf dem Breadboard](Schaltung_Breadboard.jpeg)|
|--|--|
| Schaltung logisch auf dem Breadboard | So könnte das fertige Steckbild in Wirklichkeit aussehen |

4. Für den Code gibt zwei Schwierigkeitsstufen: Nun kannst du entweder den leeren Programmrahmen aus dem Ordner `AdventWreathEmpty` oder den fertigen Code aus dem Ordner `AdventWreathComplete` auf deinen Arduino hochladen
5. Wenn alles funktioniert, baue die Kiste zusammen und verlängere die Anschlüsse der LEDs mit JumperKabeln.
6. Für den letzten Schliff: Macht einen 3D-Druck vom [Adventskranz](kranz.stl) um die LEDs in Form zu halten

## Referenzen

* Schaltung basiert auf Vorlage von [Christian Grieger](https://elektro.turanis.de/html/prj404/index.html)
* Vorlage 3D-gedruckter Kranz: [Betsmo (Thingiverse)](https://www.thingiverse.com/thing:1937138), Lizenz CC-BY

