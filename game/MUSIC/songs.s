;this file for FamiTone2 library generated by text2data tool

songs_music_data:
	.byte 4
	.word @instruments
	.word @samples-3
	.word @song0ch0,@song0ch1,@song0ch2,@song0ch3,@song0ch4,225,187
	.word @song1ch0,@song1ch1,@song1ch2,@song1ch3,@song1ch4,286,238
	.word @song2ch0,@song2ch1,@song2ch2,@song2ch3,@song2ch4,307,256
	.word @song3ch0,@song3ch1,@song3ch2,@song3ch3,@song3ch4,307,256

@instruments:
	.byte $f0 ;instrument $00
	.word @env4,@env0,@env0
	.byte $00
	.byte $b0 ;instrument $01
	.word @env10,@env0,@env0
	.byte $00
	.byte $b0 ;instrument $02
	.word @env5,@env0,@env20
	.byte $00
	.byte $30 ;instrument $03
	.word @env2,@env0,@env0
	.byte $00
	.byte $30 ;instrument $04
	.word @env3,@env0,@env0
	.byte $00
	.byte $b0 ;instrument $05
	.word @env10,@env0,@env19
	.byte $00
	.byte $30 ;instrument $06
	.word @env5,@env0,@env0
	.byte $00
	.byte $30 ;instrument $07
	.word @env6,@env0,@env0
	.byte $00
	.byte $30 ;instrument $08
	.word @env7,@env0,@env0
	.byte $00
	.byte $30 ;instrument $09
	.word @env8,@env0,@env0
	.byte $00
	.byte $30 ;instrument $0a
	.word @env9,@env0,@env20
	.byte $00
	.byte $b0 ;instrument $0b
	.word @env10,@env0,@env20
	.byte $00
	.byte $b0 ;instrument $0c
	.word @env9,@env0,@env0
	.byte $00
	.byte $b0 ;instrument $0d
	.word @env12,@env0,@env0
	.byte $00
	.byte $70 ;instrument $0f
	.word @env9,@env17,@env0
	.byte $00
	.byte $70 ;instrument $10
	.word @env9,@env16,@env0
	.byte $00
	.byte $30 ;instrument $11
	.word @env11,@env0,@env0
	.byte $00
	.byte $70 ;instrument $12
	.word @env9,@env0,@env0
	.byte $00
	.byte $70 ;instrument $13
	.word @env9,@env18,@env0
	.byte $00
	.byte $30 ;instrument $14
	.word @env9,@env0,@env0
	.byte $00
	.byte $30 ;instrument $15
	.word @env13,@env0,@env0
	.byte $00
	.byte $30 ;instrument $16
	.word @env4,@env0,@env0
	.byte $00
	.byte $b0 ;instrument $17
	.word @env9,@env0,@env19
	.byte $00
	.byte $30 ;instrument $18
	.word @env9,@env0,@env0
	.byte $00
	.byte $30 ;instrument $19
	.word @env14,@env0,@env21
	.byte $00
	.byte $30 ;instrument $1a
	.word @env15,@env0,@env22
	.byte $00
	.byte $30 ;instrument $1b
	.word @env4,@env0,@env23
	.byte $00
	.byte $30 ;instrument $1c
	.word @env12,@env0,@env0
	.byte $00
	.byte $30 ;instrument $1d
	.word @env1,@env0,@env0
	.byte $00
	.byte $30 ;instrument $1e
	.word @env9,@env0,@env19
	.byte $00

@samples:
@env0:
	.byte $c0,$00,$00
@env1:
	.byte $cc,$cc,$cb,$03,$ca,$02,$c9,$02,$c8,$03,$c7,$04,$c6,$04,$c5,$04
	.byte $c4,$06,$c3,$04,$c2,$05,$c1,$05,$c0,$00,$18
@env2:
	.byte $cf,$ca,$c7,$c4,$c3,$c2,$c1,$c0,$00,$07
@env3:
	.byte $c8,$c6,$c4,$c2,$c2,$c1,$c1,$c0,$00,$07
@env4:
	.byte $cc,$00,$00
@env5:
	.byte $c8,$02,$c7,$03,$c6,$02,$c5,$05,$c4,$02,$c3,$07,$c2,$0a,$c1,$0e
	.byte $c0,$00,$10
@env6:
	.byte $cf,$cd,$cb,$c9,$c8,$c7,$c6,$c5,$c4,$c3,$c3,$c2,$c2,$c1,$c1,$c0
	.byte $00,$0f
@env7:
	.byte $c8,$c7,$c6,$c5,$c4,$c4,$c3,$c3,$c2,$c2,$c1,$c1,$c0,$00,$0c
@env8:
	.byte $c1,$c1,$c2,$c2,$c3,$c3,$c4,$00,$06
@env9:
	.byte $c4,$00,$00
@env10:
	.byte $c8,$00,$00
@env11:
	.byte $c4,$0c,$c3,$0d,$c2,$0c,$c1,$0d,$c0,$00,$08
@env12:
	.byte $c2,$00,$00
@env13:
	.byte $c4,$c3,$c2,$c1,$c0,$00,$04
@env14:
	.byte $cf,$c9,$c6,$c3,$c0,$00,$04
@env15:
	.byte $cf,$cb,$c8,$c6,$c4,$c3,$c2,$c1,$c1,$c0,$00,$09
@env16:
	.byte $d8,$02,$d3,$02,$d0,$02,$cc,$02,$c7,$02,$c4,$02,$c0,$02,$c4,$02
	.byte $c7,$02,$cc,$02,$d0,$02,$d3,$d3,$d3,$00,$00
@env17:
	.byte $d8,$02,$d3,$02,$cf,$02,$cc,$02,$c7,$02,$c3,$02,$c0,$02,$c3,$02
	.byte $c7,$02,$cc,$02,$cf,$02,$d3,$d3,$d3,$00,$00
@env18:
	.byte $d8,$02,$d3,$02,$d1,$02,$cc,$02,$c7,$02,$c5,$02,$c0,$02,$c5,$02
	.byte $c7,$02,$cc,$02,$d1,$02,$d3,$d3,$d3,$00,$00
@env19:
	.byte $c6,$cc,$d2,$d8,$de,$e4,$ea,$f0,$f6,$fc,$ff,$16,$ff,$00,$0c
@env20:
	.byte $ba,$b7,$b7,$ba,$c0,$c6,$c9,$c9,$c6,$c0,$ba,$b7,$b7,$ba,$c0,$c6
	.byte $c9,$c9,$c6,$c0,$ba,$b7,$b7,$ba,$c0,$c6,$c9,$c9,$c6,$c0,$ba,$b7
	.byte $b7,$ba,$c0,$c6,$c9,$c9,$c6,$c0,$ba,$b7,$b7,$ba,$c0,$c6,$c9,$c9
	.byte $c6,$c0,$00,$31
@env21:
	.byte $ff,$12,$ff,$00,$02
@env22:
	.byte $d5,$ea,$ff,$12,$ff,$00,$04
@env23:
	.byte $c8,$d0,$d8,$e0,$e8,$f0,$f8,$ff,$21,$ff,$00,$09


@song0ch0:
	.byte $fb,$01
@song0ch0loop:
@ref0:
	.byte $92,$36,$b9
@ref1:
	.byte $94,$36,$b9
@ref2:
	.byte $92,$3a,$b9
@ref3:
	.byte $94,$3a,$b9
@ref4:
	.byte $92,$3c,$b9
@ref5:
	.byte $94,$3c,$b9
@ref6:
	.byte $92,$3a,$b9
@ref7:
	.byte $94,$3a,$a1,$82,$40,$89,$4a,$4c,$4e,$85
@ref8:
	.byte $a3,$96,$4e,$95
@ref9:
	.byte $a1,$00,$82,$4a,$87,$00,$4e,$87,$00
@ref10:
	.byte $4e,$89,$4e,$87,$00,$52,$89,$46,$48,$4a,$91
@ref11:
	.byte $96,$4a,$97,$84,$4a,$85,$00,$82,$46,$87,$00,$44,$87,$00
@ref12:
	.byte $46,$89,$44,$87,$00,$40,$a1
@ref13:
	.byte $96,$40,$b9
@ref14:
	.byte $84,$40,$b9
@ref15:
	.byte $a1,$00,$82,$3c,$87,$00,$36,$89
@ref16:
	.byte $95,$00,$36,$93,$00,$98,$36,$89
@ref17:
	.byte $89,$00,$94,$36,$ad
@ref18:
	.byte $92,$3a,$b9
@ref19:
	.byte $94,$3a,$b9
@ref20:
	.byte $92,$3c,$b9
@ref21:
	.byte $94,$3c,$b9
@ref22:
	.byte $92,$3a,$b9
	.byte $ff,$08
	.word @ref7
@ref24:
	.byte $a3,$96,$4e,$95
	.byte $ff,$08
	.word @ref9
	.byte $ff,$0b
	.word @ref10
@ref27:
	.byte $96,$4a,$95,$84,$4a,$87,$00,$82,$46,$87,$00,$44,$87,$00
@ref28:
	.byte $46,$89,$4a,$87,$00,$4a,$4c,$4e,$9d
@ref29:
	.byte $96,$4e,$89,$82,$3c,$95,$96,$3c,$93,$00
@ref30:
	.byte $82,$46,$89,$44,$87,$00,$40,$a1
@ref31:
	.byte $96,$40,$9f,$00,$82,$3c,$87,$00,$3e,$40,$87
@ref32:
	.byte $95,$00,$40,$93,$00,$98,$40,$89
@ref33:
	.byte $89,$00,$9a,$40,$93,$00,$97
@ref34:
	.byte $98,$64,$66,$68,$9d,$66,$83,$68,$83,$62,$60,$5e,$85
@ref35:
	.byte $8b,$58,$95,$82,$42,$44,$46,$85,$44,$87,$00
	.byte $ff,$07
	.word @ref12
@ref37:
	.byte $96,$40,$b9
@ref38:
	.byte $92,$36,$a1,$40,$95
@ref39:
	.byte $8b,$46,$93,$00,$82,$3c,$87,$00,$40,$89
@ref40:
	.byte $97,$96,$40,$93,$00,$82,$40,$89
@ref41:
	.byte $89,$00,$98,$40,$93,$00,$9a,$40,$95
@ref42:
	.byte $82,$3c,$3e,$40,$9b,$00,$44,$91,$46,$81
@ref43:
	.byte $45,$41,$45,$46,$93,$00,$4a,$93,$00
@ref44:
	.byte $4a,$4c,$4e,$9d,$96,$4e,$95
@ref45:
	.byte $89,$00,$82,$3c,$87,$8a,$3c,$89,$00,$82,$4e,$85,$50,$85,$4e,$83
	.byte $00
@ref46:
	.byte $4a,$a1,$96,$4a,$95
@ref47:
	.byte $89,$00,$82,$46,$95,$8a,$46,$87,$00,$82,$44,$87,$00
	.byte $ff,$07
	.word @ref12
@ref49:
	.byte $96,$40,$b9
@ref50:
	.byte $84,$40,$b9
@ref51:
	.byte $a1,$00,$82,$3c,$87,$00,$40,$89
@ref52:
	.byte $40,$a1,$96,$40,$95
@ref53:
	.byte $bb
@ref54:
	.byte $84,$40,$b9
	.byte $ff,$07
	.word @ref15
@ref56:
	.byte $95,$00,$98,$36,$93,$00,$9a,$36,$89
@ref57:
	.byte $89,$00,$af
@ref58:
	.byte $bb
@ref59:
	.byte $bb
@ref60:
	.byte $bb
@ref61:
	.byte $bb
@ref62:
	.byte $bb
@ref63:
	.byte $bb
	.byte $fd
	.word @song0ch0loop

@song0ch1:
@song0ch1loop:
@ref64:
	.byte $92,$2e,$b9
@ref65:
	.byte $94,$2e,$b9
@ref66:
	.byte $92,$32,$b9
@ref67:
	.byte $94,$32,$b9
@ref68:
	.byte $92,$2e,$b9
@ref69:
	.byte $94,$2e,$b9
@ref70:
	.byte $92,$32,$b9
@ref71:
	.byte $94,$32,$b9
@ref72:
	.byte $9c,$28,$b9
@ref73:
	.byte $91,$a2,$36,$83,$40,$83,$46,$83,$4e,$83,$58,$83,$5e,$83,$66,$83
@ref74:
	.byte $9e,$32,$b9
@ref75:
	.byte $8b,$a2,$7a,$83,$70,$83,$6a,$83,$70,$83,$6a,$83,$62,$83,$6a,$83
	.byte $62,$83
@ref76:
	.byte $9e,$38,$b9
@ref77:
	.byte $8b,$a2,$38,$85,$40,$85,$46,$85,$50,$85,$58,$85,$5e,$85
@ref78:
	.byte $9e,$3c,$b9
@ref79:
	.byte $a3,$ae,$26,$83,$28,$83,$2a,$83,$2c,$83
@ref80:
	.byte $2e,$b9
@ref81:
	.byte $94,$2e,$b9
@ref82:
	.byte $92,$32,$b9
@ref83:
	.byte $94,$32,$b9
@ref84:
	.byte $92,$2e,$b9
@ref85:
	.byte $94,$2e,$b9
@ref86:
	.byte $92,$32,$b9
@ref87:
	.byte $94,$32,$b7,$00
@ref88:
	.byte $9c,$28,$b9
	.byte $ff,$0f
	.word @ref73
@ref90:
	.byte $9e,$32,$b9
@ref91:
	.byte $8b,$a2,$7a,$83,$70,$83,$6a,$83,$62,$83,$58,$83,$52,$83,$4a,$83
	.byte $40,$83
@ref92:
	.byte $9e,$2e,$b9
@ref93:
	.byte $bb
@ref94:
	.byte $a4,$32,$ad,$a2,$4a,$83,$54,$83
@ref95:
	.byte $58,$83,$63,$00,$9e,$32,$ad
@ref96:
	.byte $38,$b9
@ref97:
	.byte $af,$88,$4c,$83,$4e,$83
@ref98:
	.byte $50,$83,$a8,$50,$83,$88,$58,$83,$a8,$58,$83,$88,$50,$83,$a8,$50
	.byte $83,$88,$46,$83,$a8,$46,$83,$88,$50,$83,$a8,$50,$83
@ref99:
	.byte $88,$46,$83,$a8,$46,$83,$88,$40,$83,$a8,$40,$83,$88,$46,$83,$a8
	.byte $46,$83,$88,$40,$83,$a8,$40,$83,$88,$38,$83,$a8,$38,$83
@ref100:
	.byte $81,$9c,$40,$b7
@ref101:
	.byte $bb
@ref102:
	.byte $81,$92,$2e,$a1,$32,$93
@ref103:
	.byte $8d,$36,$93,$ae,$40,$83,$46,$83,$4e,$83,$58,$83
@ref104:
	.byte $9e,$38,$b9
@ref105:
	.byte $8b,$9c,$28,$ad
@ref106:
	.byte $9e,$38,$b9
@ref107:
	.byte $8b,$a2,$38,$85,$36,$85,$38,$85,$3c,$85,$38,$85,$3c,$85
@ref108:
	.byte $a4,$2e,$a1,$2e,$95
@ref109:
	.byte $8b,$9e,$2e,$ad
@ref110:
	.byte $a4,$54,$a1,$54,$95
@ref111:
	.byte $8b,$9e,$3c,$ad
@ref112:
	.byte $9c,$4a,$b9
@ref113:
	.byte $8b,$a2,$62,$85,$58,$85,$50,$85,$58,$85,$50,$85,$4a,$85
@ref114:
	.byte $a4,$32,$a1,$32,$95
@ref115:
	.byte $8b,$9c,$32,$ad
@ref116:
	.byte $9e,$38,$b9
@ref117:
	.byte $bb
@ref118:
	.byte $98,$68,$93,$00,$68,$93,$00,$9a,$68,$89
@ref119:
	.byte $89,$00,$68,$93,$00,$97
@ref120:
	.byte $00,$b9
@ref121:
	.byte $bb
@ref122:
	.byte $bb
@ref123:
	.byte $bb
@ref124:
	.byte $bb
@ref125:
	.byte $bb
@ref126:
	.byte $bb
@ref127:
	.byte $bb
	.byte $fd
	.word @song0ch1loop

@song0ch2:
@song0ch2loop:
@ref128:
	.byte $b0,$3e,$82,$28,$93,$8a,$28,$87,$00,$b0,$3e,$82,$28,$87,$00,$89
@ref129:
	.byte $b0,$3e,$82,$28,$85,$00,$b0,$3e,$82,$28,$87,$8a,$28,$87,$00,$b0
	.byte $3e,$82,$1e,$87,$8a,$1e,$87,$00
	.byte $ff,$0b
	.word @ref128
@ref131:
	.byte $b0,$3e,$82,$28,$85,$00,$b0,$3e,$82,$28,$87,$8a,$28,$87,$00,$b0
	.byte $3e,$82,$1e,$85,$00,$b0,$3e,$82,$1e,$85,$00
	.byte $ff,$0b
	.word @ref128
	.byte $ff,$10
	.word @ref129
@ref134:
	.byte $b0,$3e,$82,$28,$91,$00,$8a,$28,$89,$b0,$3e,$82,$28,$87,$00,$89
@ref135:
	.byte $b0,$3e,$82,$1e,$85,$00,$b0,$3e,$82,$1e,$87,$8a,$1e,$87,$00,$b0
	.byte $3e,$82,$1e,$83,$b0,$3e,$8a,$1e,$83,$b0,$3e,$8a,$1e,$83
	.byte $ff,$0b
	.word @ref128
@ref137:
	.byte $b0,$3e,$82,$28,$85,$00,$b0,$3e,$82,$28,$87,$8a,$28,$87,$00,$b0
	.byte $3e,$82,$1e,$89,$8a,$1e,$85,$00
	.byte $ff,$0b
	.word @ref134
	.byte $ff,$12
	.word @ref131
	.byte $ff,$0b
	.word @ref128
	.byte $ff,$10
	.word @ref129
	.byte $ff,$0b
	.word @ref128
@ref143:
	.byte $b0,$3e,$82,$1e,$85,$00,$b0,$3e,$82,$1e,$87,$8a,$1e,$87,$00,$b0
	.byte $3e,$82,$1e,$83,$b0,$3e,$82,$1e,$83,$b0,$3e,$82,$1e,$83
@ref144:
	.byte $b0,$3e,$82,$28,$93,$8a,$28,$89,$b0,$3e,$82,$28,$87,$00,$89
@ref145:
	.byte $b0,$3e,$82,$28,$87,$b0,$3e,$82,$28,$87,$8a,$28,$89,$b0,$3e,$82
	.byte $1e,$87,$8a,$1e,$87,$00
	.byte $ff,$0a
	.word @ref144
@ref147:
	.byte $b0,$3e,$82,$28,$87,$b0,$3e,$82,$28,$87,$8a,$28,$89,$b0,$3e,$82
	.byte $1e,$87,$b0,$3e,$82,$1e,$85,$00
	.byte $ff,$0a
	.word @ref144
	.byte $ff,$0e
	.word @ref145
	.byte $ff,$0a
	.word @ref144
@ref151:
	.byte $b0,$3e,$82,$1e,$87,$b0,$3e,$82,$1e,$87,$8a,$1e,$89,$b0,$3e,$82
	.byte $1e,$83,$b0,$3e,$8a,$1e,$83,$b0,$3e,$8a,$1e,$83
	.byte $ff,$0a
	.word @ref144
	.byte $ff,$10
	.word @ref129
	.byte $ff,$0b
	.word @ref128
@ref155:
	.byte $b0,$3e,$82,$1a,$85,$00,$b0,$3e,$82,$28,$87,$8a,$28,$87,$00,$b0
	.byte $3e,$82,$28,$85,$00,$b0,$3e,$82,$2c,$85,$00
@ref156:
	.byte $b0,$3e,$80,$2e,$93,$8a,$2e,$87,$00,$b0,$3e,$80,$2e,$87,$00,$89
@ref157:
	.byte $b0,$3e,$80,$2e,$85,$00,$b0,$3e,$80,$2e,$91,$00,$b0,$3e,$80,$16
	.byte $91,$00
@ref158:
	.byte $b0,$3e,$80,$32,$93,$8a,$32,$87,$00,$b0,$3e,$82,$32,$87,$00,$89
@ref159:
	.byte $b0,$3e,$82,$28,$85,$00,$b0,$3e,$82,$32,$91,$00,$b0,$3e,$82,$1a
	.byte $91,$00
@ref160:
	.byte $b0,$3e,$80,$20,$93,$8a,$20,$87,$00,$b0,$3e,$82,$20,$87,$00,$89
@ref161:
	.byte $b0,$3e,$82,$16,$85,$00,$b0,$3e,$82,$20,$91,$00,$b0,$3e,$82,$08
	.byte $91,$00
@ref162:
	.byte $b0,$3e,$82,$20,$85,$00,$b0,$3e,$82,$20,$87,$00,$89,$b0,$3e,$82
	.byte $20,$85,$00,$8b
@ref163:
	.byte $b0,$3e,$82,$16,$85,$00,$b0,$3e,$82,$20,$91,$00,$b0,$3e,$82,$20
	.byte $85,$00,$b0,$3e,$82,$20,$85,$00
	.byte $ff,$0b
	.word @ref128
@ref165:
	.byte $b0,$3e,$82,$28,$85,$00,$b0,$3e,$82,$28,$87,$8a,$28,$87,$00,$b0
	.byte $3e,$82,$28,$87,$8a,$1e,$87,$00
	.byte $ff,$0b
	.word @ref128
	.byte $ff,$12
	.word @ref131
	.byte $ff,$0b
	.word @ref160
	.byte $ff,$0c
	.word @ref161
	.byte $ff,$0b
	.word @ref160
@ref171:
	.byte $b0,$3e,$82,$16,$85,$00,$b0,$3e,$82,$20,$91,$00,$b0,$3e,$82,$0c
	.byte $83,$b0,$3e,$82,$0c,$83,$b0,$3e,$82,$0c,$83
@ref172:
	.byte $b0,$3e,$82,$2e,$93,$8a,$2e,$87,$00,$b0,$3e,$82,$2e,$87,$00,$89
@ref173:
	.byte $b0,$3e,$82,$24,$85,$00,$b0,$3e,$82,$2e,$91,$00,$b0,$3e,$82,$16
	.byte $91,$00
@ref174:
	.byte $b0,$3e,$82,$24,$93,$8a,$24,$87,$00,$b0,$3e,$82,$24,$87,$00,$89
@ref175:
	.byte $b0,$3e,$82,$1a,$85,$00,$b0,$3e,$82,$24,$91,$00,$b0,$3e,$82,$0c
	.byte $91,$00
@ref176:
	.byte $b0,$3e,$82,$1a,$93,$8a,$1a,$87,$00,$b0,$3e,$82,$1a,$87,$00,$89
@ref177:
	.byte $b0,$3e,$82,$10,$85,$00,$b0,$3e,$82,$1a,$91,$00,$b0,$3e,$82,$02
	.byte $91,$00
	.byte $ff,$0b
	.word @ref176
@ref179:
	.byte $b0,$3e,$82,$10,$85,$00,$b0,$3e,$82,$1a,$91,$00,$b0,$3e,$82,$1a
	.byte $85,$00,$b0,$3e,$82,$1e,$85,$00
@ref180:
	.byte $b0,$3e,$82,$20,$93,$8a,$20,$87,$00,$b0,$3e,$82,$20,$87,$00,$89
@ref181:
	.byte $b0,$3e,$82,$16,$85,$00,$b0,$3e,$82,$20,$91,$00,$b0,$3e,$82,$20
	.byte $83,$b0,$3e,$82,$20,$83,$b0,$3e,$82,$20,$83
	.byte $ff,$0b
	.word @ref180
	.byte $ff,$11
	.word @ref181
	.byte $ff,$0b
	.word @ref128
	.byte $ff,$10
	.word @ref129
	.byte $ff,$0b
	.word @ref128
	.byte $ff,$12
	.word @ref131
	.byte $ff,$0b
	.word @ref128
	.byte $ff,$10
	.word @ref129
	.byte $ff,$0b
	.word @ref134
	.byte $ff,$13
	.word @ref135
	.byte $fd
	.word @song0ch2loop

@song0ch3:
@song0ch3loop:
@ref192:
	.byte $8c,$12,$9f,$00,$90,$18,$89,$88,$1e,$89
@ref193:
	.byte $1e,$89,$86,$1e,$89,$88,$1e,$89,$90,$18,$89,$88,$1e,$83,$86,$1e
	.byte $83
@ref194:
	.byte $1e,$89,$88,$1e,$89,$1e,$89,$90,$18,$89,$88,$1e,$89
@ref195:
	.byte $1e,$89,$86,$1e,$89,$88,$1e,$89,$90,$18,$89,$18,$89
@ref196:
	.byte $86,$1e,$89,$88,$1e,$89,$1e,$89,$90,$18,$89,$88,$1e,$89
	.byte $ff,$0c
	.word @ref193
	.byte $ff,$0a
	.word @ref194
@ref199:
	.byte $1e,$89,$86,$1e,$89,$88,$1e,$89,$8e,$18,$85,$18,$85,$18,$85
	.byte $ff,$07
	.word @ref192
@ref201:
	.byte $1e,$89,$86,$1e,$89,$88,$1e,$89,$90,$18,$89,$88,$1e,$83,$1e,$83
@ref202:
	.byte $8b,$1e,$89,$1e,$89,$90,$18,$89,$88,$1e,$89
	.byte $ff,$0a
	.word @ref195
	.byte $ff,$0a
	.word @ref196
	.byte $ff,$0c
	.word @ref193
	.byte $ff,$0a
	.word @ref194
@ref207:
	.byte $1e,$89,$86,$1e,$89,$88,$1e,$89,$90,$18,$85,$18,$85,$18,$85
	.byte $ff,$07
	.word @ref192
	.byte $ff,$0c
	.word @ref193
	.byte $ff,$0a
	.word @ref194
	.byte $ff,$0a
	.word @ref195
	.byte $ff,$0a
	.word @ref196
	.byte $ff,$0c
	.word @ref193
	.byte $ff,$0a
	.word @ref194
	.byte $ff,$0c
	.word @ref199
	.byte $ff,$07
	.word @ref192
	.byte $ff,$0c
	.word @ref193
@ref218:
	.byte $8b,$88,$1e,$89,$1e,$89,$90,$18,$89,$88,$1e,$89
	.byte $ff,$0a
	.word @ref195
	.byte $ff,$0a
	.word @ref196
	.byte $ff,$0c
	.word @ref193
	.byte $ff,$0a
	.word @ref194
@ref223:
	.byte $1e,$89,$86,$1e,$89,$88,$1e,$89,$90,$18,$89,$18,$83,$86,$1e,$83
@ref224:
	.byte $8c,$12,$a1,$90,$18,$89,$88,$1e,$89
	.byte $ff,$0c
	.word @ref193
@ref226:
	.byte $90,$18,$89,$18,$89,$1e,$89,$8e,$1e,$89,$90,$1e,$89
@ref227:
	.byte $8e,$1e,$89,$90,$18,$89,$1e,$89,$8e,$1e,$89,$90,$18,$89
	.byte $ff,$07
	.word @ref192
	.byte $ff,$0c
	.word @ref193
	.byte $ff,$0a
	.word @ref194
	.byte $ff,$0a
	.word @ref195
@ref232:
	.byte $8c,$12,$a1,$90,$18,$95
@ref233:
	.byte $88,$1e,$89,$86,$1e,$89,$88,$1e,$89,$90,$18,$89,$88,$1e,$83,$86
	.byte $1e,$83
	.byte $ff,$0a
	.word @ref194
	.byte $ff,$0c
	.word @ref207
	.byte $ff,$04
	.word @ref232
	.byte $ff,$0c
	.word @ref233
@ref238:
	.byte $8c,$10,$a1,$90,$18,$95
	.byte $ff,$0c
	.word @ref233
@ref240:
	.byte $a0,$12,$9d,$01,$90,$18,$95
	.byte $ff,$0c
	.word @ref233
@ref242:
	.byte $a0,$12,$9d,$01,$90,$18,$89,$88,$1e,$89
	.byte $ff,$0c
	.word @ref193
	.byte $ff,$0a
	.word @ref194
	.byte $ff,$0c
	.word @ref193
	.byte $ff,$0a
	.word @ref194
@ref247:
	.byte $1e,$89,$86,$1e,$89,$88,$1e,$89,$90,$18,$85,$18,$85,$8e,$18,$85
	.byte $ff,$07
	.word @ref192
	.byte $ff,$0c
	.word @ref193
	.byte $ff,$0a
	.word @ref194
	.byte $ff,$0a
	.word @ref195
	.byte $ff,$0a
	.word @ref196
	.byte $ff,$0c
	.word @ref193
	.byte $ff,$0a
	.word @ref194
	.byte $ff,$0c
	.word @ref199
	.byte $fd
	.word @song0ch3loop

@song0ch4:
@song0ch4loop:
@ref256:
	.byte $bb
@ref257:
	.byte $bb
@ref258:
	.byte $bb
@ref259:
	.byte $bb
@ref260:
	.byte $bb
@ref261:
	.byte $bb
@ref262:
	.byte $bb
@ref263:
	.byte $bb
@ref264:
	.byte $bb
@ref265:
	.byte $bb
@ref266:
	.byte $bb
@ref267:
	.byte $bb
@ref268:
	.byte $bb
@ref269:
	.byte $bb
@ref270:
	.byte $bb
@ref271:
	.byte $bb
@ref272:
	.byte $bb
@ref273:
	.byte $bb
@ref274:
	.byte $bb
@ref275:
	.byte $bb
@ref276:
	.byte $bb
@ref277:
	.byte $bb
@ref278:
	.byte $bb
@ref279:
	.byte $bb
@ref280:
	.byte $bb
@ref281:
	.byte $bb
@ref282:
	.byte $bb
@ref283:
	.byte $bb
@ref284:
	.byte $bb
@ref285:
	.byte $bb
@ref286:
	.byte $bb
@ref287:
	.byte $bb
@ref288:
	.byte $bb
@ref289:
	.byte $bb
@ref290:
	.byte $bb
@ref291:
	.byte $bb
@ref292:
	.byte $bb
@ref293:
	.byte $bb
@ref294:
	.byte $bb
@ref295:
	.byte $bb
@ref296:
	.byte $bb
@ref297:
	.byte $bb
@ref298:
	.byte $bb
@ref299:
	.byte $bb
@ref300:
	.byte $bb
@ref301:
	.byte $bb
@ref302:
	.byte $bb
@ref303:
	.byte $bb
@ref304:
	.byte $bb
@ref305:
	.byte $bb
@ref306:
	.byte $bb
@ref307:
	.byte $bb
@ref308:
	.byte $bb
@ref309:
	.byte $bb
@ref310:
	.byte $bb
@ref311:
	.byte $bb
@ref312:
	.byte $bb
@ref313:
	.byte $bb
@ref314:
	.byte $bb
@ref315:
	.byte $bb
@ref316:
	.byte $bb
@ref317:
	.byte $bb
@ref318:
	.byte $bb
@ref319:
	.byte $bb
	.byte $fd
	.word @song0ch4loop


@song1ch0:
	.byte $fb,$02
@song1ch0loop:
@ref320:
	.byte $8b
@ref321:
	.byte $83
@ref322:
	.byte $a6,$12,$83,$00,$12,$83,$00,$0e,$83,$00,$08,$83,$00
@ref323:
	.byte $0e,$83,$00,$12,$83,$00,$87,$16,$85
@ref324:
	.byte $85,$00,$12,$83,$00,$0e,$83,$00,$08,$83,$00
@ref325:
	.byte $0e,$83,$00,$12,$83,$00,$87,$18,$85
	.byte $ff,$0b
	.word @ref324
@ref327:
	.byte $0e,$83,$00,$12,$83,$00,$87,$04,$85
@ref328:
	.byte $85,$00,$0e,$83,$00,$12,$83,$00,$08,$85
@ref329:
	.byte $85,$00,$10,$83,$00,$12,$83,$00,$12,$83,$00
	.byte $ff,$0b
	.word @ref324
	.byte $ff,$09
	.word @ref323
	.byte $ff,$0b
	.word @ref324
	.byte $ff,$09
	.word @ref325
	.byte $ff,$0b
	.word @ref324
	.byte $ff,$09
	.word @ref327
	.byte $ff,$0a
	.word @ref328
@ref337:
	.byte $85,$00,$16,$83,$00,$12,$83,$00,$12,$83,$00
	.byte $ff,$0b
	.word @ref324
	.byte $ff,$09
	.word @ref323
	.byte $ff,$0b
	.word @ref324
	.byte $ff,$09
	.word @ref325
	.byte $ff,$0b
	.word @ref324
	.byte $ff,$09
	.word @ref327
	.byte $ff,$0a
	.word @ref328
@ref345:
	.byte $85,$00,$10,$83,$00,$12,$83,$00,$0a,$85
@ref346:
	.byte $85,$00,$22,$83,$00,$0a,$83,$00,$0a,$83,$00
@ref347:
	.byte $22,$83,$00,$0a,$83,$00,$8d,$00
@ref348:
	.byte $0a,$83,$00,$0a,$83,$01,$23,$00,$0b,$ba,$0a,$81
@ref349:
	.byte $85,$00,$a6,$0a,$83,$00,$85,$00,$0e,$85
@ref350:
	.byte $85,$00,$26,$83,$00,$0e,$83,$00,$0e,$83,$00
@ref351:
	.byte $26,$83,$00,$0e,$83,$00,$8d,$00
@ref352:
	.byte $0e,$8b,$00,$0e,$8b,$00
@ref353:
	.byte $08,$83,$00,$08,$83,$00,$8f
@ref354:
	.byte $aa,$72,$85,$b4,$72,$83,$00,$8c,$72,$8b,$00
@ref355:
	.byte $a0,$72,$8b,$00,$b6,$72,$8b,$00
@ref356:
	.byte $82,$46,$48,$4a,$91,$4c,$85
@ref357:
	.byte $85,$00,$50,$8d,$8a,$50,$83,$00
@ref358:
	.byte $82,$56,$58,$5a,$91,$96,$5a,$85
@ref359:
	.byte $8d,$00,$9a,$5a,$8b,$00
@ref360:
	.byte $81,$82,$54,$56,$99
@ref361:
	.byte $96,$56,$93,$00,$82,$4c,$4e,$50,$81
@ref362:
	.byte $8d,$00,$98,$50,$8b,$00
@ref363:
	.byte $9a,$50,$8b,$00,$50,$8b,$00
@ref364:
	.byte $9f
@ref365:
	.byte $9f
@ref366:
	.byte $9f
@ref367:
	.byte $9f
@ref368:
	.byte $9f
@ref369:
	.byte $9f
@ref370:
	.byte $9f
@ref371:
	.byte $9f
@ref372:
	.byte $9f
@ref373:
	.byte $9f
@ref374:
	.byte $9f
@ref375:
	.byte $9f
@ref376:
	.byte $9f
@ref377:
	.byte $9f
	.byte $fd
	.word @song1ch0loop

@song1ch1:
@song1ch1loop:
@ref378:
	.byte $8b
@ref379:
	.byte $83
	.byte $ff,$08
	.word @ref354
	.byte $ff,$06
	.word @ref355
@ref382:
	.byte $9f
@ref383:
	.byte $9f
@ref384:
	.byte $9f
@ref385:
	.byte $9f
@ref386:
	.byte $9f
@ref387:
	.byte $97,$aa,$72,$85
@ref388:
	.byte $b4,$72,$83,$00,$8c,$72,$8b,$00,$a0,$72,$85
@ref389:
	.byte $85,$00,$b6,$72,$8b,$00,$87
@ref390:
	.byte $9f
@ref391:
	.byte $9f
@ref392:
	.byte $9f
@ref393:
	.byte $9f
@ref394:
	.byte $98,$6e,$70,$72,$99
@ref395:
	.byte $70,$85,$ac,$70,$87,$9a,$70,$83,$9e,$30,$85
@ref396:
	.byte $9f
@ref397:
	.byte $81,$30,$93,$34,$85
@ref398:
	.byte $9f
@ref399:
	.byte $81,$1c,$93,$9c,$38,$85
@ref400:
	.byte $9f
@ref401:
	.byte $81,$20,$93,$a4,$1c,$85
@ref402:
	.byte $97,$9e,$20,$85
@ref403:
	.byte $97,$3a,$85
@ref404:
	.byte $9f
@ref405:
	.byte $81,$9c,$42,$9b
@ref406:
	.byte $83,$88,$57,$4d,$4d,$47,$47,$4d,$4c,$81
@ref407:
	.byte $47,$47,$3f,$3e,$89,$a4,$3e,$85
@ref408:
	.byte $9f
@ref409:
	.byte $9e,$26,$9d
@ref410:
	.byte $90,$6f,$65,$61,$57,$4d,$47,$43,$3e,$00
@ref411:
	.byte $a4,$20,$83,$00,$9e,$20,$83,$00,$8f
@ref412:
	.byte $88,$42,$85,$39,$a8,$43,$88,$35,$a8,$39,$88,$33,$a8,$34,$81
@ref413:
	.byte $88,$43,$a8,$33,$88,$39,$a8,$43,$88,$35,$a8,$39,$88,$33,$a8,$34
	.byte $81
	.byte $ff,$09
	.word @ref413
	.byte $ff,$09
	.word @ref413
	.byte $ff,$09
	.word @ref413
	.byte $ff,$09
	.word @ref413
@ref418:
	.byte $88,$47,$a8,$33,$88,$43,$a8,$47,$88,$3f,$a8,$43,$88,$35,$a8,$3e
	.byte $81
@ref419:
	.byte $88,$47,$a8,$3f,$88,$43,$a8,$47,$88,$3f,$a8,$43,$88,$35,$a8,$3e
	.byte $81
@ref420:
	.byte $88,$49,$a8,$3f,$88,$47,$a8,$49,$88,$3f,$a8,$47,$88,$39,$a8,$3e
	.byte $81
	.byte $ff,$09
	.word @ref420
	.byte $ff,$09
	.word @ref420
	.byte $ff,$09
	.word @ref420
@ref424:
	.byte $9f
@ref425:
	.byte $9f
@ref426:
	.byte $9f
@ref427:
	.byte $9f
@ref428:
	.byte $9f
@ref429:
	.byte $9f
@ref430:
	.byte $9f
@ref431:
	.byte $9f
@ref432:
	.byte $9f
@ref433:
	.byte $9f
@ref434:
	.byte $9f
@ref435:
	.byte $9f
	.byte $fd
	.word @song1ch1loop

@song1ch2:
@song1ch2loop:
@ref436:
	.byte $8b
@ref437:
	.byte $83
@ref438:
	.byte $b0,$3e,$a6,$2a,$83,$b0,$3e,$a6,$2b,$00,$b2,$46,$a6,$27,$00,$20
	.byte $83,$00
@ref439:
	.byte $b0,$3e,$a6,$27,$00,$b0,$3e,$a6,$2b,$00,$b2,$46,$01,$00,$b0,$3e
	.byte $a6,$16,$83
@ref440:
	.byte $85,$00,$b0,$3e,$a6,$2b,$00,$b2,$46,$a6,$27,$00,$20,$83,$00
@ref441:
	.byte $b0,$3e,$a6,$27,$00,$b0,$3e,$a6,$2b,$00,$b2,$46,$01,$00,$b0,$3e
	.byte $a6,$18,$83
	.byte $ff,$0b
	.word @ref440
@ref443:
	.byte $b0,$3e,$a6,$27,$00,$b0,$3e,$a6,$2b,$00,$b2,$46,$01,$00,$b0,$3e
	.byte $a6,$1c,$83
@ref444:
	.byte $85,$00,$b0,$3e,$a6,$27,$00,$b2,$46,$a6,$2b,$00,$b0,$3e,$a6,$20
	.byte $83
@ref445:
	.byte $85,$00,$b2,$46,$a6,$29,$00,$b2,$46,$a6,$2b,$00,$b0,$3e,$a6,$2b
	.byte $00
@ref446:
	.byte $87,$b0,$3e,$a6,$2b,$00,$b2,$46,$a6,$27,$00,$20,$83,$00
	.byte $ff,$0c
	.word @ref439
	.byte $ff,$0b
	.word @ref440
	.byte $ff,$0c
	.word @ref441
	.byte $ff,$0b
	.word @ref440
	.byte $ff,$0c
	.word @ref443
	.byte $ff,$0b
	.word @ref444
@ref453:
	.byte $85,$00,$b2,$46,$a6,$2f,$00,$b2,$46,$a6,$2b,$00,$b0,$3e,$a6,$2b
	.byte $00
	.byte $ff,$0a
	.word @ref446
	.byte $ff,$0c
	.word @ref439
	.byte $ff,$0b
	.word @ref440
	.byte $ff,$0c
	.word @ref441
	.byte $ff,$0b
	.word @ref440
	.byte $ff,$0c
	.word @ref443
	.byte $ff,$0b
	.word @ref444
@ref461:
	.byte $85,$00,$b2,$46,$a6,$29,$00,$b2,$46,$a6,$2b,$00,$b0,$3e,$a6,$22
	.byte $83
@ref462:
	.byte $85,$00,$b0,$3e,$a6,$3b,$00,$b2,$46,$a6,$23,$00,$22,$83,$00
@ref463:
	.byte $b0,$3e,$a6,$3b,$00,$b0,$3e,$a6,$23,$00,$b2,$46,$00,$89,$00
@ref464:
	.byte $b0,$3e,$a6,$23,$00,$b0,$3e,$a6,$23,$00,$b2,$46,$a6,$3b,$00,$b0
	.byte $3e,$a6,$23,$ba,$22
@ref465:
	.byte $85,$00,$b0,$3e,$a6,$23,$00,$b2,$46,$01,$00,$b0,$3e,$a6,$26,$83
@ref466:
	.byte $85,$00,$b0,$3e,$a6,$3f,$00,$b2,$46,$a6,$27,$00,$26,$83,$00
@ref467:
	.byte $b0,$3e,$a6,$3f,$00,$b0,$3e,$a6,$27,$00,$b2,$46,$00,$89,$00
@ref468:
	.byte $46,$a6,$27,$00,$b0,$3e,$a6,$27,$00,$b2,$46,$a6,$27,$00,$b0,$3e
	.byte $a6,$27,$00
@ref469:
	.byte $b0,$3e,$a6,$21,$00,$b0,$3e,$a6,$21,$00,$b2,$46,$00,$83,$b0,$3e
	.byte $00,$83
@ref470:
	.byte $3e,$a6,$2b,$00,$b0,$3e,$a6,$2b,$00,$b2,$46,$00,$83,$a6,$20,$83
	.byte $00
@ref471:
	.byte $b0,$3e,$a6,$2b,$00,$b0,$3e,$a6,$2b,$00,$b2,$46,$01,$00,$b0,$3e
	.byte $a6,$21,$00
@ref472:
	.byte $2a,$83,$00,$b0,$3e,$a6,$2b,$00,$b2,$46,$00,$83,$a6,$20,$83,$00
@ref473:
	.byte $b0,$3e,$a6,$2b,$00,$b0,$3e,$a6,$2b,$00,$b2,$46,$00,$83,$a6,$20
	.byte $83,$00
	.byte $ff,$0c
	.word @ref473
@ref475:
	.byte $b0,$3e,$a6,$2b,$00,$b0,$3e,$a6,$2b,$00,$b2,$46,$01,$00,$b0,$3e
	.byte $a6,$1d,$00
@ref476:
	.byte $2e,$83,$00,$b0,$3e,$a6,$2f,$00,$b2,$46,$00,$83,$a6,$1c,$83,$00
@ref477:
	.byte $b0,$3e,$a6,$2f,$00,$b0,$3e,$a6,$2f,$00,$b2,$46,$00,$83,$a6,$1c
	.byte $83,$00
@ref478:
	.byte $b0,$3e,$a6,$31,$00,$b0,$3e,$a6,$31,$00,$b2,$46,$00,$83,$a6,$26
	.byte $83,$00
@ref479:
	.byte $b0,$3e,$a6,$31,$00,$b0,$3e,$a6,$31,$00,$b2,$46,$01,$00,$b0,$3e
	.byte $a6,$27,$00
@ref480:
	.byte $30,$83,$00,$b0,$3e,$a6,$31,$00,$b2,$46,$00,$83,$a6,$26,$83,$00
@ref481:
	.byte $b0,$3e,$a6,$31,$00,$b0,$3e,$a6,$31,$00,$b2,$46,$00,$83,$a6,$26
	.byte $85
@ref482:
	.byte $9f
@ref483:
	.byte $9f
@ref484:
	.byte $9f
@ref485:
	.byte $9f
@ref486:
	.byte $9f
@ref487:
	.byte $9f
@ref488:
	.byte $9f
@ref489:
	.byte $9f
@ref490:
	.byte $9f
@ref491:
	.byte $9f
@ref492:
	.byte $9f
@ref493:
	.byte $9f
	.byte $fd
	.word @song1ch2loop

@song1ch3:
@song1ch3loop:
@ref494:
	.byte $88,$15,$15,$10,$81
@ref495:
	.byte $0c,$81
@ref496:
	.byte $b8,$12,$9d
@ref497:
	.byte $90,$1e,$85,$88,$1e,$85,$86,$08,$85,$88,$1e,$85
	.byte $ff,$08
	.word @ref497
@ref499:
	.byte $90,$1e,$85,$88,$1e,$85,$86,$08,$85,$90,$1e,$85
@ref500:
	.byte $88,$1e,$85,$90,$1e,$85,$86,$08,$85,$88,$1e,$85
	.byte $ff,$08
	.word @ref497
	.byte $ff,$08
	.word @ref497
@ref503:
	.byte $90,$1e,$85,$86,$08,$85,$08,$85,$8c,$12,$85
@ref504:
	.byte $8f,$86,$08,$85,$88,$1f,$1a,$81
@ref505:
	.byte $86,$1e,$85,$88,$1e,$85,$86,$08,$85,$88,$1e,$85
	.byte $ff,$08
	.word @ref497
	.byte $ff,$08
	.word @ref499
	.byte $ff,$08
	.word @ref500
	.byte $ff,$08
	.word @ref497
@ref510:
	.byte $90,$1e,$85,$88,$1e,$85,$86,$08,$85,$8c,$1e,$85
@ref511:
	.byte $87,$86,$09,$09,$07,$05,$8c,$12,$85
	.byte $ff,$06
	.word @ref504
	.byte $ff,$08
	.word @ref505
	.byte $ff,$08
	.word @ref497
	.byte $ff,$08
	.word @ref499
	.byte $ff,$08
	.word @ref500
	.byte $ff,$08
	.word @ref497
	.byte $ff,$08
	.word @ref510
	.byte $ff,$07
	.word @ref511
@ref520:
	.byte $8f,$86,$08,$85,$88,$1e,$85
	.byte $ff,$08
	.word @ref497
	.byte $ff,$08
	.word @ref510
@ref523:
	.byte $90,$1e,$85,$88,$1e,$85,$86,$08,$85,$8c,$12,$85
	.byte $ff,$05
	.word @ref520
@ref525:
	.byte $90,$1e,$85,$88,$1e,$85,$86,$08,$85,$88,$1f,$1e,$81
@ref526:
	.byte $86,$08,$85,$88,$1e,$85,$86,$08,$85,$8c,$1e,$85
@ref527:
	.byte $90,$1e,$85,$88,$1e,$85,$15,$15,$11,$0c,$81
@ref528:
	.byte $8c,$12,$8d,$86,$08,$85,$88,$1e,$85
	.byte $ff,$08
	.word @ref497
	.byte $ff,$08
	.word @ref497
	.byte $ff,$08
	.word @ref499
	.byte $ff,$08
	.word @ref500
	.byte $ff,$08
	.word @ref497
	.byte $ff,$08
	.word @ref497
	.byte $ff,$08
	.word @ref497
	.byte $ff,$06
	.word @ref528
	.byte $ff,$08
	.word @ref497
	.byte $ff,$08
	.word @ref497
	.byte $ff,$08
	.word @ref499
@ref540:
	.byte $9f
@ref541:
	.byte $9f
@ref542:
	.byte $9f
@ref543:
	.byte $9f
@ref544:
	.byte $9f
@ref545:
	.byte $9f
@ref546:
	.byte $9f
@ref547:
	.byte $9f
@ref548:
	.byte $9f
@ref549:
	.byte $9f
@ref550:
	.byte $9f
@ref551:
	.byte $9f
	.byte $fd
	.word @song1ch3loop

@song1ch4:
@song1ch4loop:
@ref552:
	.byte $8b
@ref553:
	.byte $83
@ref554:
	.byte $9f
@ref555:
	.byte $9f
@ref556:
	.byte $9f
@ref557:
	.byte $9f
@ref558:
	.byte $9f
@ref559:
	.byte $9f
@ref560:
	.byte $9f
@ref561:
	.byte $9f
@ref562:
	.byte $9f
@ref563:
	.byte $9f
@ref564:
	.byte $9f
@ref565:
	.byte $9f
@ref566:
	.byte $9f
@ref567:
	.byte $9f
@ref568:
	.byte $9f
@ref569:
	.byte $9f
@ref570:
	.byte $9f
@ref571:
	.byte $9f
@ref572:
	.byte $9f
@ref573:
	.byte $9f
@ref574:
	.byte $9f
@ref575:
	.byte $9f
@ref576:
	.byte $9f
@ref577:
	.byte $9f
@ref578:
	.byte $9f
@ref579:
	.byte $9f
@ref580:
	.byte $9f
@ref581:
	.byte $9f
@ref582:
	.byte $9f
@ref583:
	.byte $9f
@ref584:
	.byte $9f
@ref585:
	.byte $9f
@ref586:
	.byte $9f
@ref587:
	.byte $9f
@ref588:
	.byte $9f
@ref589:
	.byte $9f
@ref590:
	.byte $9f
@ref591:
	.byte $9f
@ref592:
	.byte $9f
@ref593:
	.byte $9f
@ref594:
	.byte $9f
@ref595:
	.byte $9f
@ref596:
	.byte $9f
@ref597:
	.byte $9f
@ref598:
	.byte $9f
@ref599:
	.byte $9f
@ref600:
	.byte $9f
@ref601:
	.byte $9f
@ref602:
	.byte $9f
@ref603:
	.byte $9f
@ref604:
	.byte $9f
@ref605:
	.byte $9f
@ref606:
	.byte $9f
@ref607:
	.byte $9f
@ref608:
	.byte $9f
@ref609:
	.byte $9f
	.byte $fd
	.word @song1ch4loop


@song2ch0:
	.byte $fb,$06
@song2ch0loop:
@ref610:
	.byte $f9,$85
	.byte $fd
	.word @song2ch0loop

@song2ch1:
@song2ch1loop:
@ref611:
	.byte $f9,$85
	.byte $fd
	.word @song2ch1loop

@song2ch2:
@song2ch2loop:
@ref612:
	.byte $f9,$85
	.byte $fd
	.word @song2ch2loop

@song2ch3:
@song2ch3loop:
@ref613:
	.byte $f9,$85
	.byte $fd
	.word @song2ch3loop

@song2ch4:
@song2ch4loop:
@ref614:
	.byte $f9,$85
	.byte $fd
	.word @song2ch4loop


@song3ch0:
	.byte $fb,$06
@song3ch0loop:
@ref615:
	.byte $f9,$85
	.byte $fd
	.word @song3ch0loop

@song3ch1:
@song3ch1loop:
@ref616:
	.byte $f9,$85
	.byte $fd
	.word @song3ch1loop

@song3ch2:
@song3ch2loop:
@ref617:
	.byte $f9,$85
	.byte $fd
	.word @song3ch2loop

@song3ch3:
@song3ch3loop:
@ref618:
	.byte $f9,$85
	.byte $fd
	.word @song3ch3loop

@song3ch4:
@song3ch4loop:
@ref619:
	.byte $f9,$85
	.byte $fd
	.word @song3ch4loop